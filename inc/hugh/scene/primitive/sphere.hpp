// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/sphere.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_PRIMITIVE_SPHERE_HPP)

#define HUGH_SCENE_PRIMITIVE_SPHERE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/node/geometry.hpp>

namespace hugh {
  
  namespace scene {

    namespace primitive {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT sphere : public node::geometry {

      public:

        using subject_inherited = node::geometry;

        static unsigned const dflt_subdivision; // == 4
      
        explicit sphere(unsigned = dflt_subdivision);

        field::value::single<unsigned> subdivision; //< sub-division levels
      
        virtual void accept(visitor::base&);

      protected:

        virtual void do_changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace primitive {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_PRIMITIVE_SPHERE_HPP)
