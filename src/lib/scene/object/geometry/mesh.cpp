// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/mesh.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/mesh.hpp"

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // variables, exported
    
        // functions, exported

        /* explicit */
        mesh::mesh(attribute_list_type const& a, index_list_type const& b)
          : base()
        {
          TRACE("hugh::scene::object::geometry::mesh::mesh");

          attribute_list_ = a;
          index_list_     = b;

          compute_bounds();
          compute_tangents();
        }
        
      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
