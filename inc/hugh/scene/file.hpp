// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/file.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_FILE_HPP)

#define HUGH_SCENE_FILE_HPP

// includes, system

#include <boost/noncopyable.hpp> // boost::noncopyable
#include <string>                // std::string

// includes, project

#include <hugh/scene/export.h>

namespace hugh {
  
  namespace scene {

    namespace node {

      class group;

    } // namespace node

    namespace file {
    
      // types, exported (class, enum, struct, union, typedef)
    
      enum class type {
        detect
      };
    
      class HUGH_SCENE_EXPORT handler : private boost::noncopyable {

      public:
      
        static HUGH_SCENE_EXPORT node::group* load(std::string const& /* name */,
                                                   type               /* type */ = type::detect);
        static HUGH_SCENE_EXPORT bool         save(std::string const& /* name */,
                                                   node::group*       /* scene */,
                                                   type               /* type */ = type::detect);
                               
      };                         

      // variables, exported (extern)

      // functions, inlined (inline)

      // functions, exported (extern)

    } // namespace file {

  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_FILE_HPP)
