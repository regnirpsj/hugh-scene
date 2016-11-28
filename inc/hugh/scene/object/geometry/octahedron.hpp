// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/octahedron.hpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_GEOMETRY_OCTAHEDRON_HPP)

#define HUGH_SCENE_OBJECT_GEOMETRY_OCTAHEDRON_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/geometry/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT octahedron : public base {

        public:
        
          explicit octahedron();
      
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_GEOMETRY_OCTAHEDRON_HPP)
