// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/icosahedron.cpp                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/icosahedron.hpp"

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

  using namespace hugh::scene::object;
  
  // variables, internal
  
  // functions, internal

  void
  make_icosahedron(geometry::base::attribute_list_type& /* attr_list */,
                   geometry::base::index_list_type&     /* index_list */)
  {
    TRACE("hugh::scene::object::geometry::icosahedron::<unnamed>::make_icosahedron");
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // variables, exported
    
        // functions, exported

        /* explicit */
        icosahedron::icosahedron()
          : base()
        {
          TRACE("hugh::scene::object::geometry::icosahedron::icosahedron");

          attribute_list_.clear();
          index_list_    .clear();
          
          make_icosahedron(attribute_list_, index_list_);
      
          compute_bounds();
          compute_tangents();
        }

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
