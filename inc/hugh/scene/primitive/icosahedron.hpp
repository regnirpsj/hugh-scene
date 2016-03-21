// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/icosahedron.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_PRIMITIVE_ICOSAHEDRON_HPP)

#define HUGH_SCENE_PRIMITIVE_ICOSAHEDRON_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/node/geometry.hpp>

namespace hugh {
  
  namespace scene {

    namespace primitive {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT icosahedron : public node::geometry {

      public:

        using subject_inherited = node::geometry;

        explicit icosahedron();
      
        virtual void accept(visitor::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace primitive {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_PRIMITIVE_ICOSAHEDRON_HPP)
