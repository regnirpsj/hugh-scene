// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/tetrahedron.hpp                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_GEOMETRY_TETRAHEDRON_HPP)

#define HUGH_SCENE_OBJECT_GEOMETRY_TETRAHEDRON_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/geometry/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT tetrahedron : public base {

        public:

          explicit tetrahedron();
      
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_GEOMETRY_TETRAHEDRON_HPP)
