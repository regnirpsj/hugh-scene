// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/load.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP)

#define UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP

// includes, system

#include <string> // std::string

// includes, project

//#include <>

namespace gli {

  class texture;
  
} // namespace gli {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
  
        // types, exported (class, enum, struct, union, typedef)

        // variables, exported (extern)

        // functions, inlined (inline)
      
        // functions, exported (extern)

        gli::texture load(std::string const& /* file name */);
      
      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(UKACHULLDCS_08961_SCENE_OBJECT_TEXTURE_SHARED_HPP)
