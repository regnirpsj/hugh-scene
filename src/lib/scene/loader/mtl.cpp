// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/loader/mtl.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// TODO: sync w/ 'obj2pbrt.cpp' in pbrt-v3 [http://github.com/mmp/pbrt-v3/]

// include i/f header

#include "loader/mtl.hpp"

// includes, system

// altough dealing w/ lowering the noise level for boost::spirit headers,
// the pragmas need to be here
#if defined(_MSC_VER) && (_MSC_VER < 1800)
// warning C4100: 'x' : unreferenced formal parameter
#  pragma warning(disable:4100)
// warning C4127: conditional expression is constant
#  pragma warning(disable:4127)
#endif

#include <boost/algorithm/string.hpp>                // boost::trim[_copy]
#include <boost/config/warning_disable.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/tokenizer.hpp>                       // boost::char_separator<>, boost::tokenizer<>
#include <cmath>                                     // std::pow
#include <fstream>                                   // std::[i|o]fstream
#include <glm/gtx/io.hpp>
#include <istream>                                   // std::istream
#include <ostream>                                   // std::ostream

// includes, project

#include <hugh/support/type_info.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

#if defined(HUGH_USE_TRACE)
#  include <boost/fusion/include/io.hpp>
#  include <glm/gtx/io.hpp>
#endif

BOOST_FUSION_ADAPT_STRUCT(glm::vec3,
                          (glm::vec3::value_type, x)
                          (glm::vec3::value_type, y)
                          (glm::vec3::value_type, z)
                          );

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace qi    = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;
  
  template <typename IT>
  struct rgb_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    rgb_parser()
      : rgb_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::mtl::<unnamed>::rgb_parser::rgb_parser");
        
      using qi::debug;
      using qi::float_;
        
      start %=
        float_ >>  // x
        float_ >>  // y
        float_     // z
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec3(), ascii::space_type> start;
    
  };

  template <typename IT>
  struct xyz_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    xyz_parser()
      : xyz_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::mtl::<unnamed>::xyz_parser::xyz_parser");
        
      using qi::debug;
      using qi::float_;
      using qi::lit;
      
      start %=
        lit("xyz") >>  // "xyz"
        float_     >>  // x
        float_     >>  // y
        float_         // z
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec3(), ascii::space_type> start;
    
  };
  
  template <typename IT>
  struct float_parser : qi::grammar<IT, float(), ascii::space_type> {
    
    float_parser()
      : float_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::mtl::<unnamed>::float_parser::float_parser");
        
      using qi::debug;
      using qi::float_;
        
      start %=
        float_
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, float(), ascii::space_type> start;
    
  };

  template <typename IT>
  struct integer_parser : qi::grammar<IT, signed(), ascii::space_type> {
    
    integer_parser()
      : integer_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::mtl::<unnamed>::integer_parser::integer_parser");
        
      using qi::debug;
      using qi::int_;
        
      start %=
        int_
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, signed(), ascii::space_type> start;
    
  };
  
  // variables, internal
  
  // functions, internal

  template <typename P, typename O>
  inline bool
  parse(std::string const& exp, O& o)
  {
    TRACE_NEVER("hugh::scene::file::mtl::<unamed>::parse<" +
                support::demangle(typeid(P)) + "," + support::demangle(typeid(O)) + ">");
        
    auto       first (exp.begin());
    auto       last  (exp.end());
    bool const result(phrase_parse(first, last, P(), ascii::space, o));

#if 0 // defined(HUGH_USE_TRACE)
    if (result && first == last) {
      std::cout << support::trace::prefix() << "hugh::scene::file::mtl::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << boost::fusion::tuple_open('[')
                << boost::fusion::tuple_close(']')
                << boost::fusion::tuple_delimiter(", ")
                << "in:'" << exp << "', out:" << o
                << std::endl;
    } else {
      std::cout << support::trace::prefix() << "hugh::scene::file::mtl::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << "failed to parse '" << exp << "'" << std::endl;
    }
#endif
        
    return (result && first == last);
  }

  /*
   * see [http://www.wikipedia.org/wiki/SRGB]
   */
  inline glm::vec3
  xyz_to_rgb(glm::vec3 const& xyz)
  {
    static float const     a  ( 0.055f);
    static float const     b  (12.920f);
    static glm::mat3 const c  (+3.2406, -1.5372, -0.4986,
                               -0.9689, +1.8758, +0.0415,
                               +0.0557, -0.2040, +1.0570);
    static float const     lim(0.0031308f);
    static float const     exp(1.0f / 2.4f);
    
    glm::vec3 result(c * (xyz / glm::vec3(100.0)));
    
    result.r = (result.r > lim) ? ((1.0f + a) * std::pow(result.r, exp)) : (b * result.r);
    result.g = (result.g > lim) ? ((1.0f + a) * std::pow(result.g, exp)) : (b * result.g);
    result.b = (result.b > lim) ? ((1.0f + a) * std::pow(result.b, exp)) : (b * result.b);
    
    return result;
  }

  inline std::string
  get_map_name(std::string const& a)
  {
    std::string result(a);

#if 0
    std::cout << support::trace::prefix() << "hugh::scene::file::mtl::<unnamed>::get_map_name: "
              << "'" << a << "'"
              << std::endl;
#endif
    
    return result;
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace file {

      namespace mtl {
      
        // variables, exported
  
        // functions, exported

        list_type
        load(std::istream& is)
        {
          TRACE("hugh::scene::file::mtl::load(std::istream)");

          list_type result;

          {
            result.push_back(new scene::object::material::simple);

            (*result.rbegin())->name = "default material";
          }
        
          std::string line;

          while (std::getline(is, line)) {
            boost::trim       (line);
            boost::replace_all(line, "\t", " ");
            
            if (line.empty() ||
                ('#'  == line[0]) ||
                ('!'  == line[0]) ||
                ('$'  == line[0]) ||
                ('\r' == line[0])) {
              continue;
            }
            
            static boost::char_separator<char> const token_separator_space(" ");
          
            using tokenizer = boost::tokenizer<boost::char_separator<char>>;
        
            tokenizer tokens(line, token_separator_space);
            
            if      (("bump"     == *tokens.begin()) || // bump -options args filename
                     ("map_bump" == *tokens.begin())) { // map_bump -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("d" == *tokens.begin()) { // d [-halo] f
              auto start(line.begin() + (*tokens.begin()).length());

              {
                auto next(tokens.begin());

                ++next;
              
                if ("-halo" == *next) {
                  start += 1 + (*next).length() + 1; // <space> + -halo + <space>
                }
              }
            
              std::string const exp(start, line.end());
              float             d;
              
              if (parse<float_parser<std::string::const_iterator>>(exp, d)) {
                (*result.rbegin())->alpha = d;
              }
            }

            else if ("decal" == *tokens.begin()) { // decal -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("disp" == *tokens.begin()) { // disp -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("illum" == *tokens.begin()) { // illum #
#if 0
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              signed            illum;
              
              if (parse<integer_parser<std::string::const_iterator>>(exp, illum)) {
                std::ostringstream ostr;
              
                switch (illum) {
                case  0: ostr << "Color on and Ambient off"; break;
                case  1: ostr << "Color on and Ambient on"; break;
                case  2: ostr << "Highlight on"; break;
                case  3: ostr << "Reflection on and Ray trace on"; break;
                case  4: ostr << "Transparency: Glass on,      Reflection: Ray trace on"; break;
                case  5: ostr << "Reflection:   Fresnel on and Ray trace on"; break;
                case  6: ostr << "Transparency: Refraction on, Reflection: Fresnel off and Ray trace on"; break;
                case  7: ostr << "Transparency: Refraction on, Reflection: Fresnel on and Ray trace on"; break;
                case  8: ostr << "Reflection on and Ray trace off"; break;
                case  9: ostr << "Glass on,      Reflection: Ray trace off"; break;
                case 10: ostr << "Casts shadows onto invisible surfaces"; break;
                default: ostr << "unknown illumination model #" << illum; break;
                }

                std::cout << support::trace::prefix()
                          << "hugh::scene::file::mtl::load(std::istream): "
                          << "material '" << *(*result.rbegin())->name << "': " << ostr.str()
                          << std::endl;
              }
#endif
            }
          
            else if ("Ka" == *tokens.begin()) { // Ka [r g b] | [spectral file.refl f] | [xyz x y z]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              glm::vec3         c;
              
              if      (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->ambient = c;
              }

              else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->ambient = xyz_to_rgb(c);
              }
            }

            else if ("Ke" == *tokens.begin()) { // Ke [r g b] | [spectral file.refl f] | [xyz x y z]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              glm::vec3         c;
              
              if      (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->emission = c;
              }

              else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->emission = xyz_to_rgb(c);
              }
            }
          
            else if ("Kd" == *tokens.begin()) { // Kd [r g b] | [spectral file.refl f] | [xyz x y z]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              glm::vec3         c;
              
              if      (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->diffuse = c;
              }

              else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->diffuse = xyz_to_rgb(c);
              }
            }

            else if ("Ks" == *tokens.begin()) { // Ks [r g b] | [spectral file.refl f] | [xyz x y z]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              glm::vec3         c;
              
              if      (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->specular = c;
              }

              else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->specular = xyz_to_rgb(c);
              }
            }
          
            else if ("map_d" == *tokens.begin()) { // map_d -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }

            else if ("map_Ka" == *tokens.begin()) { // map_Ka -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }

            else if ("map_Ke" == *tokens.begin()) { // map_Ka -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("map_Kd" == *tokens.begin()) { // map_Kd -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("map_Ks" == *tokens.begin()) { // map_Ks -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }

            else if ("map_Ns" == *tokens.begin()) { // map_Ns -options args filename
              get_map_name(std::string(line.begin() + (*tokens.begin()).length() + 1, line.end()));
            }
          
            else if ("Ni" == *tokens.begin()) { // Ni f
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              float             r;
              
              if (parse<float_parser<std::string::const_iterator>>(exp, r)) {
                (*result.rbegin())->refraction = r;
              }
            }
          
            else if ("Ns" == *tokens.begin()) { // Ns exp
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              float             s;
              
              if (parse<float_parser<std::string::const_iterator>>(exp, s)) {
                (*result.rbegin())->shininess = s;
              }
            }
          
            else if ("newmtl" == *tokens.begin()) { // newmtl <string>
              result.push_back(new scene::object::material::simple);

              (*result.rbegin())->name = boost::trim_copy(std::string(line.begin() +
                                                                      (*tokens.begin()).length(),
                                                                      line.end()));
            }
          
            else if ("refl" == *tokens.begin()) { // refl -type <type> -options -args filename
              auto start(line.begin() + (*tokens.begin()).length());

              {
                auto next(tokens.begin());

                ++next;

                // <type>: [sphere|cube_[back|bottom|front|left|right|top]]
                if ("-type" == *next) {
                  start += 1 + (*next).length() + 1; // <space> + -type + <space>

                  ++next;

                  start += (*next).length() + 1;     // <type> + <space>
                }
              }

              get_map_name(std::string(start, line.end()));
            }

            else if ("sharpness" == *tokens.begin()) { // sharpness f
              // nothing to do (yet)
            }
          
            else if ("Tf" == *tokens.begin()) { // Tf [r g b] | [spectral file.refl f] | [xyz x y z]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              glm::vec3         c;
              
              if (parse<rgb_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->transmission = c;
              } else if (parse<xyz_parser<std::string::const_iterator>>(exp, c)) {
                (*result.rbegin())->transmission = xyz_to_rgb(c);
              }
            }
          
            else if ("Tr" == *tokens.begin()) { // Tr x (== 1 - alpha)
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              float             t;
              
              if (parse<float_parser<std::string::const_iterator>>(exp, t)) {
                (*result.rbegin())->alpha = (1.0f - t);
              }
            }

            else if ("TWOSIDE" == *tokens.begin()) { // TWOSIDE (non-standard)
              (*result.rbegin())->front = true;
              (*result.rbegin())->back  = true;
            }

            else {
              std::cout << support::trace::prefix()
                        << "hugh::scene::file::mtl::load(std::istream): "
                        << "unhandled token '" << *tokens.begin() << "'; skipping "
                        << "whole line '" << line << "'" << std::endl;
            }
          }

          return result;
        }
      
        list_type
        load(std::string const& a)
        {
          TRACE("hugh::scene::file::mtl::load(std::string) [" + a + "]");

          list_type     result;
          std::ifstream ifs(a, std::ios::in|std::ios::binary);
        
          if (ifs.is_open()) {
            result = load(ifs);
          }
        
          return result;
        }
      
        bool
        save(std::ostream&, list_type const&)
        {
          TRACE("hugh::scene::file::mtl::save(std::ostream)");

          return false;
        }
      
        bool
        save(std::string const& a, list_type const& b)
        {
          TRACE("hugh::scene::file::mtl::save(std::string) [" + a + "]");

          bool          result(false);
          std::ofstream ofs(a, std::ios::out|std::ios::binary|std::ios::trunc);

          if (ofs.is_open()) {
            result = save(ofs, b);
          }
        
          return result;
        }
      
      } // namespace mtl {
    
    } // namespace file {
  
  } // namespace scene {

} // namespace hugh {
