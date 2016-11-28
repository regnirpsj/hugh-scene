// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/loader/obj.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "loader/obj.hpp"

// includes, system

// altough dealing w/ lowering the noise level for boost::spirit headers,
// the pragmas need to be here
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
// warning C4100: 'x' : unreferenced formal parameter
#  pragma warning(disable:4100)
// warning C4127: conditional expression is constant
#  pragma warning(disable:4127)
#endif

#include <array>                                     // std::array<>
#include <boost/algorithm/string.hpp>                // boost::trim[_copy]
#include <boost/config/warning_disable.hpp>
#include <boost/filesystem.hpp>                      // boost::filesystem::*
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/tokenizer.hpp>                       // boost::char_separator<>, boost::tokenizer<>
#include <fstream>                                   // std::[i|o]fstream
#include <glm/gtx/io.hpp>                            // glm::operator<<
#include <istream>                                   // std::istream
#include <numeric>                                   // std::iota
#include <ostream>                                   // std::ostream

// includes, project

// #include <>

#include <hugh/scene/node/group.hpp>
#include <hugh/scene/node/material_group.hpp>
#include <hugh/scene/node/mesh.hpp>
#include <loader/mtl.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#include <hugh/support/type_info.hpp>

#if defined(HUGH_USE_TRACE)
#  include <boost/fusion/include/io.hpp>
#  include <hugh/support/io_utils.hpp>
#endif

// internal unnamed namespace

// arrgh, that really needs to be in global scope
BOOST_FUSION_ADAPT_STRUCT(glm::ivec3,
                          (glm::ivec3::value_type, x)
                          (glm::ivec3::value_type, y)
                          (glm::ivec3::value_type, z)
                          );

BOOST_FUSION_ADAPT_STRUCT(glm::vec3,
                          (glm::vec3::value_type, x)
                          (glm::vec3::value_type, y)
                          (glm::vec3::value_type, z)
                          );

BOOST_FUSION_ADAPT_STRUCT(glm::vec4,
                          (glm::vec4::value_type, x)
                          (glm::vec4::value_type, y)
                          (glm::vec4::value_type, z)
                          (glm::vec4::value_type, w)
                          );
  
namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace qi    = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  template <typename IT>
  struct face_parser : qi::grammar<IT, glm::ivec3(), ascii::space_type> {
    
    face_parser()
      : face_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::obj::<unnamed>::face_parser::face_parser");

      using qi::attr;
      using qi::debug;
      using qi::int_;
      using qi::lit;
        
      start %=
        int_                               >> // v
        -( lit('/') >> (int_ | attr(0) ) ) >> // t
        -( lit('/') >> (int_ | attr(0) ) )    // n
        ;
        
      // debug(start);
    }
    
    qi::rule<IT, glm::ivec3(), ascii::space_type> start;
    
  };
  
  template <typename IT>
  struct normal_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    normal_parser()
      : normal_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::obj::<unnamed>::normal_parser::normal_parser");
        
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
  struct tcoord_parser : qi::grammar<IT, glm::vec3(), ascii::space_type> {
    
    tcoord_parser()
      : tcoord_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::obj::<unnamed>::tcoord_parser::tcoord_parser");

      using qi::attr;
      using qi::debug;
      using qi::float_;
        
      start %=
        float_                  >> // u
        -( float_ | attr(0.0) ) >> // v
        -( float_ | attr(0.0) )    // w
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec3(), ascii::space_type> start;
    
  };
  
  template <typename IT>
  struct vertex_parser : qi::grammar<IT, glm::vec4(), ascii::space_type> {
    
    vertex_parser()
      : vertex_parser::base_type(start)
    {
      TRACE_NEVER("hugh::scene::file::obj::<unnamed>::vertex_parser::vertex_parser");
        
      using qi::attr;
      using qi::debug;
      using qi::float_;

      // 
      start %=
        float_                  >>  // x
        float_                  >>  // y
        float_                  >>  // z
        -( float_ | attr(1.0) )     // w
        ;        
        
      // debug(start);
    }
    
    qi::rule<IT, glm::vec4(), ascii::space_type> start;
    
  };
  
  // variables, internal
  
  // functions, internal

  template <typename P, typename O>
  inline bool
  parse(std::string const& exp, O& o)
  {
    TRACE_NEVER("hugh::scene::file::obj::<unnamed>::parse<" +
                support::demangle(typeid(P)) + "," + support::demangle(typeid(O)) + ">");
        
    auto       first (exp.begin());
    auto       last  (exp.end());
    bool const result(phrase_parse(first, last, P(), ascii::space, o));

#if 0 // defined(HUGH_USE_TRACE)
    if (result && first == last) {
      std::cout << support::trace::prefix() << "hugh::scene::file::obj::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << boost::fusion::tuple_open('[')
                << boost::fusion::tuple_close(']')
                << boost::fusion::tuple_delimiter(", ")
                << "in:'" << exp << "', out:" << o
                << std::endl;
    } else {
      std::cout << support::trace::prefix() << "hugh::scene::file::obj::parse<"
                << support::demangle(typeid(P)) << ',' << support::demangle(typeid(O)) << ">: "
                << "failed to parse '" << exp << "'" << std::endl;
    }
#endif
        
    return (result && first == last);
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace file {

      namespace obj {
      
        // variables, exported
  
        // functions, exported
      
        scene::node::group*
        load(std::istream& is, path_list_type const& path_list)
        {
          TRACE("hugh::scene::file::obj::load(std::istream)");
        
          using face_type        = std::vector<glm::ivec3>;
          using normal_type      = glm::vec3;
          using object_type      = std::tuple<std::string, unsigned, unsigned, std::string>;
          using tcoord_type      = glm::vec3;
          using vertex_type      = glm::vec4;
          using face_list_type   = std::vector<face_type>;
          using normal_list_type = std::vector<normal_type>;
          using object_list_type = std::vector<object_type>;
          using tcoord_list_type = std::vector<tcoord_type>;
          using vertex_list_type = std::vector<vertex_type>;
        
          face_list_type   face_list;
          mtl::list_type   material_list;
          normal_list_type normal_list;
          object_list_type object_list;
          tcoord_list_type tcoord_list;
          vertex_list_type vertex_list;
          std::string      current_material_name("dflt");
          std::string      line;
        
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
            
            if      ("f" == *tokens.begin()) { // f v/[t]/[n]
              face_type f;
              
              for (auto const& t : tokens) {
                std::string const     exp(t.begin(), t.end());
                face_type::value_type c;
                
                if (parse<face_parser<std::string::const_iterator>>(exp, c)) {
                  { // correct negative indices
                    if (0 > c.x) { c.x += vertex_list.size() + 1; }
                    if (0 > c.y) { c.y += tcoord_list.size() + 1; }
                    if (0 > c.z) { c.z += normal_list.size() + 1; }
                  }

                  { // set default for indices into empty v/t/n lists
                    if (vertex_list.empty()) { c.x = 0; }
                    if (tcoord_list.empty()) { c.y = 0; }
                    if (normal_list.empty()) { c.z = 0; }
                  }
                
                  f.push_back(c);
                }
              }
              
              face_list.push_back(f);
            }

            else if ("mtllib" == *tokens.begin()) { // mtllib <string> [...]
              auto current(++(tokens.begin()));

              while (tokens.end() != current) {
                bool        found(true);
                std::string f    (boost::trim_copy(*current));
              
                if (!boost::filesystem::exists(boost::filesystem::path(f))) {
                  found = false;
                
                  for (auto const& e : path_list) {
                    boost::filesystem::path p(e);

                    p /= f;
                  
                    if (boost::filesystem::exists(p)) {
                      f = p.string();
                    
                      found = true;

                      break;
                    }
                  }
                }

                if (found) {
                  mtl::list_type const l(mtl::load(f));
                
                  material_list.insert(material_list.end(), l.begin(), l.end());
                }
              
                ++current;
              }
            }
          
            else if ("usemtl" == *tokens.begin()) { // usemtl <string>
              current_material_name = std::string(line.begin() + (*tokens.begin()).length(),
                                                  line.end());

              boost::trim(current_material_name);

              if (!object_list.empty()) {
                object_type& o(*object_list.rbegin());
              
                std::get<3>(o) = current_material_name;
              }
            }
          
            else if (("g" == *tokens.begin()) || // g <string> [<string> ...]
                     ("o" == *tokens.begin())) { // o <string>
              if (!object_list.empty()) {
                object_type& o(*object_list.rbegin());

                std::get<2>(o) = face_list.size() - std::get<1>(o);
              }

              std::string const name(line.begin() + (*tokens.begin()).length(), line.end());
              
              object_list.push_back(std::make_tuple(boost::trim_copy(name),
                                                    face_list.size(), // face list idx
                                                    0,                // face list range
                                                    current_material_name));
            }

            else if ("s" == *tokens.begin()) { // s <number> | off
              // ignore
            }

            else if ("mg" == *tokens.begin()) { // mg <number>
              // ignore
            }
          
            else if ("v" == *tokens.begin()) { // v x y z [w]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              vertex_type       v;
              
              if (parse<vertex_parser<std::string::const_iterator>>(exp, v)) {
                vertex_list.push_back(v);
              }
            }
            
            else if ("vn" == *tokens.begin()) { // vn x y z
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              normal_type       n;
              
              if (parse<normal_parser<std::string::const_iterator>>(exp, n)) {
                normal_list.push_back(n);
              }
            }            
            
            else if ("vt" == *tokens.begin()) { // vt u [v [w]]
              std::string const exp(line.begin() + (*tokens.begin()).length(), line.end());
              tcoord_type       tc;
              
              if (parse<tcoord_parser<std::string::const_iterator>>(exp, tc)) {
                tcoord_list.push_back(tc);
              }
            }
            
            else {
              std::cout << support::trace::prefix()
                        << "hugh::scene::file::obj::load(std::istream): "
                        << "unhandled token '" << *tokens.begin() << "'; skipping "
                        << "whole line '" << line << "'" << std::endl;
            }
          }
        
          if (!object_list.empty()) {
            object_type& o(*object_list.rbegin());

            std::get<2>(o) = face_list.size() - std::get<1>(o);

            object_list_type::iterator current(object_list.begin());

            // remove objects w/o faces
            while (object_list.end() != current) {
              object_type& c(*current);

              if (1 > std::get<2>(c)) {
                current = object_list.erase(current);
              } else {
                ++current;
              }
            }
          }

          // have faces but no object -> create default object
          else if (!face_list.empty()) {
            object_list.push_back(std::make_tuple("unnamed",
                                                  0,                // face list idx
                                                  face_list.size(), // face list range
                                                  current_material_name));
          }
        
          scene::node::group* result(nullptr);

          if (!object_list.empty()) {
            using namespace scene::node;
          
            result = new group(/* "unnamed" */);

            for (auto const& o : object_list) {
              auto const&     found(std::find_if(material_list.begin(), material_list.end(),
                                                 [o](mtl::list_type::const_reference v){
                                                   return (std::get<3>(o) == v->name.get());
                                                 }));
              material_group* mg(new material_group);
            
              if (material_list.end() != found) {
                mg->name     = std::get<3>(o);
                mg->material = *found;
              }
            
              {

#if 0 // defined(HUGH_USE_TRACE)
                {
                  glm::io::format_saver const iofs(std::cout);

                  std::cout << glm::io::precision(1)
                            << glm::io::width(1 + 1 + 1 + 1);
            
                  std::cout << "f[" << std::get<1>(o) << '+' << std::get<2>(o) << ']'
                            << ",v:" << vertex_list.size()
                            << ",n:" << normal_list.size()
                            << ",t:" << tcoord_list.size()
                            << '\n';
              
                  for (unsigned i(std::get<1>(o)); i < (std::get<1>(o) + std::get<2>(o)); ++i) {
                    using support::ostream::operator<<;
                
                    std::cout << "f[" << i << "]  :" << face_list[i] << '\n'
                              << "f[" << i << "].v:";

                    for (auto const& f : face_list[i]) {
                      std::cout << vertex_list[f.x - 1] << ',';
                    }

                    std::cout << support::ostream::remove(1) << '\n'
                              << "f[" << i << "].t:";

                    for (auto const& f : face_list[i]) {
                      if (0 < f.y) {
                        std::cout << tcoord_list[f.y - 1] << ',';
                      }
                    }
                
                    std::cout << support::ostream::remove(1) << '\n'
                              << "f[" << i << "].n:";

                    for (auto const& f : face_list[i]) {
                      if (0 < f.z) {
                        std::cout << normal_list[f.z - 1] << ',';
                      }
                    }
                
                    std::cout << support::ostream::remove(1) << "\n\n";
                  }
                }
#endif
              
                geometry::attribute_list_type attrs;
              
                for (unsigned i(std::get<1>(o)); i < (std::get<1>(o) + std::get<2>(o)); ++i) {
                  using attribute = geometry::attribute;

                  static glm::vec4 const dflt(0.0);
                
                  switch (face_list[i].size()) {
                  case 3:
                    for (auto const& v : face_list[i]) {
                      attrs.push_back(attribute(vertex_list[v.x-1].xyz,
                                                (0 < v.z) ? normal_list[v.z-1].xyz : dflt.xyz,
                                                (0 < v.y) ? tcoord_list[v.y-1].xy  : dflt.xy));
                    }
                    break;

                  case 4:
                    {
                      std::array<attribute const, 4> const tmp = {
                        {
                          attribute(vertex_list[face_list[i][0].x-1].xyz(),
                                    ((0 < face_list[i][0].z) ?
                                     normal_list[face_list[i][0].z-1].xyz() : dflt.xyz()),
                                    ((0 < face_list[i][0].y) ?
                                     tcoord_list[face_list[i][0].y-1].xy()  : dflt.xy())),
                        
                          attribute(vertex_list[face_list[i][1].x-1].xyz(),
                                    ((0 < face_list[i][1].z) ?
                                     normal_list[face_list[i][1].z-1].xyz() : dflt.xyz()),
                                    ((0 < face_list[i][1].y) ?
                                     tcoord_list[face_list[i][1].y-1].xy()  : dflt.xy())),
                        
                          attribute(vertex_list[face_list[i][2].x-1].xyz(),
                                    ((0 < face_list[i][2].z) ?
                                     normal_list[face_list[i][2].z-1].xyz() : dflt.xyz()),
                                    ((0 < face_list[i][2].y) ?
                                     tcoord_list[face_list[i][2].y-1].xy()  : dflt.xy())),
                        
                          attribute(vertex_list[face_list[i][3].x-1].xyz(),
                                    ((0 < face_list[i][3].z) ?
                                     normal_list[face_list[i][3].z-1].xyz() : dflt.xyz()),
                                    ((0 < face_list[i][3].y) ?
                                     tcoord_list[face_list[i][3].y-1].xy()  : dflt.xy())),
                        }
                      };

                      attrs.push_back(tmp[0]); attrs.push_back(tmp[1]); attrs.push_back(tmp[2]);
                      attrs.push_back(tmp[2]); attrs.push_back(tmp[3]); attrs.push_back(tmp[0]);
                    }
                    break;
                  
                  default:
                    std::cout << support::trace::prefix()
                              << "hugh::scene::file::obj::load(std::istream): "
                              << "handling of face w/ " << face_list[i].size()
                              << " vert" << ((1 == face_list[i].size()) ? "ex" : "ices")
                              << " not yet implemented"
                              << std::endl;
                    break;
                  }
                }

                {
                  geometry::index_list_type idx(attrs.size());

                  std::iota(idx.begin(), idx.end(), 0);
                
                  mg->children += new mesh(attrs, idx);
                }
              }
            
              result->children += mg;
            }
          
#if defined(HUGH_USE_TRACE)
            {
              glm::io::format_saver const iofs(std::cout);

              std::cout << glm::io::precision(1)
                        << glm::io::width(1 + 1 + 1 + 1);
            
              for (auto const& m : material_list) {
                std::cout << support::trace::prefix()
                          << "hugh::scene::file::obj::load(std::istream): "
                          << "m:'" << *m.get()
                          << '\n';
              }
            
              std::cout << support::trace::prefix()
                        << "hugh::scene::file::obj::load(std::istream): ";
              
              for (auto const& o : object_list) {
                std::cout << "o:'"
                          << std::get<0>(o) << "',["
                          << std::get<1>(o) << '+'
                          << std::get<2>(o) << "],'"
                          << std::get<3>(o) << "',";
              }

              std::cout << "f:" << face_list.size()   << ','
                        << "n:" << normal_list.size() << ','
                        << "t:" << tcoord_list.size() << ','
                        << "v:" << vertex_list.size()
                        << '\n';
            }
#endif
          }
        
          return result;
        }
      
        scene::node::group*
        load(std::string const& a, path_list_type const& b)
        {
          TRACE("hugh::scene::file::obj::load(std::string) [" + a + "]");

          scene::node::group* result(nullptr);
          std::ifstream       ifs   (a, std::ios::in|std::ios::binary);

          if (ifs.is_open()) {
            path_list_type plist(b);
          
            plist.push_front(boost::filesystem::path(a).parent_path().string());
          
            result = load(ifs, plist);

            if (result) {
              result->name = a;
            }
          }
        
          return result;
        }

        bool
        save(std::ostream&, scene::node::group*)
        {
          TRACE("hugh::scene::file::obj::save(std::ostream)");
    
          return false;
        }
      
        bool
        save(std::string const& a, scene::node::group* b)
        {
          TRACE("hugh::scene::file::obj::save(std::string) [" + a + "]");

          bool          result(false);
          std::ofstream ofs(a, std::ios::out|std::ios::binary|std::ios::trunc);

          if (ofs.is_open()) {
            result = save(ofs, b);
          }
        
          return result;
        }

      } // namespace obj {
    
    } // namespace file {
  
  } // namespace scene {

} // namespace hugh {
