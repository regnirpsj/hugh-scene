// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/loader/xform.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_LOADER_XFORM_HPP)

#define HUGH_SCENE_LOADER_XFORM_HPP

// includes, system

#include <string> // std::string

// includes, project

// #include <>

namespace hugh {
  
  namespace scene {

    namespace node {

      class group;
    
    } // namespace node

    namespace file {

      namespace xform {
      
        // types, exported (class, enum, struct, union, typedef)
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

        node::group* load(std::string const&);
        bool         save(std::string const&, node::group*);
      
      } // namespace xform {
    
    } // namespace file {

  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_LOADER_XFORM_HPP)
