// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/icosahedron.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/primitive/icosahedron.hpp"

// includes, system

//#include <>

// includes, project

#include <hugh/scene/visitor/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using namespace hugh::scene;
  
  // variables, internal
  
  // functions, internal

  void
  make_icosahedron(node::geometry::attribute_list_type& /* attr_list */,
                   node::geometry::index_list_type&     /* index_list */)
  {
    TRACE("hugh::scene::primitive::icosahedron::<unnamed>::make_icosahedron");
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace primitive {
    
      // variables, exported
    
      // functions, exported

      /* explicit */
      icosahedron::icosahedron()
        : node::geometry()
      {
        TRACE("hugh::scene::primitive::icosahedron::icosahedron");

        make_icosahedron(attribute_list_, index_list_);
      
        compute_bounds();
        compute_tangents();
      }
    
      /* virtual */ void
      icosahedron::accept(visitor::base& v)
      {
        TRACE("hugh::scene::primitive::icosahedron::accept");

        v.visit(*this);
      }
    
    } // namespace primitive {
  
  } // namespace scene {

} // namespace hugh {
