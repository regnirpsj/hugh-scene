// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/geometry.hpp"

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

  // variables, internal
  
  // functions, internal
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // variables, exported
    
      // functions, exported
    
      /* explicit */
      geometry::geometry(object::geometry::base* a)
        : base  (),
          object(*this, "object", a)
      {
        TRACE("hugh::scene::node::geometry::geometry");
      }

      /* virtual */ void
      geometry::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::geometry::accept");

        v.visit(*this);
      }

      void
      geometry::compute_bounds()
      {
        TRACE("hugh::scene::node::geometry::compute_bounds");

        bounds                         b(bounds::invalid);
        object_ptr_type::element_type* o(object->get());
        
        if (o) {
          o->compute_bounds();

          b = o->bbox.get();
        }

        bbox = b;
      }
      
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
