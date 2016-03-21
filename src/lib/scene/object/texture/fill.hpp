// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/fill.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_TEXTURE_FILL_HPP)

#define HUGH_SCENE_OBJECT_TEXTURE_FILL_HPP

// includes, system

//#include <>

// includes, project

// #include <>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
  
        // types, exported (class, enum, struct, union, typedef)

        // variables, exported (extern)

        // functions, inlined (inline)

        template <typename T, typename C>
        void fill(T& /* target */, C const& /* proto */);
      
        // functions, exported (extern)
  
      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#include <object/texture/fill.inl>

#endif // #if !defined(HUGH_SCENE_OBJECT_TEXTURE_FILL_HPP)
