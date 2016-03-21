// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/mesh.hpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_MESH_HPP)

#define HUGH_SCENE_NODE_MESH_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/scene/node/geometry.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT mesh : public geometry {

      public:

        using subject_inherited = geometry;
      
        using attribute_list_type = geometry::attribute_list_type;
        using index_list_type     = geometry::index_list_type;
      
        explicit mesh(attribute_list_type const&, index_list_type const&);
      
        virtual void accept(visitor::base&);

        void compute_normals();
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_MESH_HPP)
