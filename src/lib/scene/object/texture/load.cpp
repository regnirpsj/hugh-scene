// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/load.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "object/texture/load.hpp"

// includes, system

#if defined(_MSC_VER) && (_MSC_VER <= 1800)
// warning C4310: cast truncates constant value
#  pragma warning(disable:4310)
#endif

#include <array>                // std::array<>
#include <boost/filesystem.hpp> // boost::filesystem::path
#include <functional>           // std::function<>, std::placeholders::*
#include <gli/gli.hpp>          // gli::*
#include <ostream>              // std::ostream
#include <unordered_map>        // std::unordered_map<>

// includes, project

#include <gli/gtx/io.hpp>
#include <hugh/support/hasher.hpp>
#include <hugh/support/string.hpp>
#include <hugh/support/type_info.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#endif

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
  
        // variables, exported
  
        // functions, exported

        gli::texture
        load(std::string const& fname)
        {
          TRACE("hugh::scene::object::texture::load");

#if 0
          typedef std::function<gli::storage (char const*)> load_function_type;
          typedef std::unordered_map<std::string const,
                                     load_function_type>    suffix_map_type;

          // see [https://stackoverflow.com/questions/12500411]
          typedef gli::texture (*load_function_ctype)(char const*);
        
          static std::array<suffix_map_type::value_type, 1> const suffix_array = {
            {
              std::make_pair(".dds", std::bind(static_cast<load_function_ctype>(&gli::load_dds),
                                               std::placeholders::_1)),
            } 
          };
          static suffix_map_type const suffix_map(suffix_array.begin(), suffix_array.end());
    
          gli::texture result(gli::FORMAT_RGBA8_UNORM, gli::texture::extent_type(1, 1, 1));

          try {
            namespace bfs = boost::filesystem;
      
            std::string const  ext(bfs::path(fname).extension().string());
            gli::storage const tmp(suffix_map.at(ext)(fname.c_str()));
      
            if (!tmp.empty()) {
              result = tmp;
            } 
          }

          catch (std::exception&) { /* */ }
                               
          return result;
#else
          return gli::load(fname);
#endif
        }
      
      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {
  
} // namespace hugh {
