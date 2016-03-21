// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/cylinder.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/primitive/cylinder.hpp"

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
  make_cylinder(unsigned                             /* sides */,
                node::geometry::attribute_list_type& /* attr_list */,
                node::geometry::index_list_type&     /* index_list */)
  {
    TRACE("hugh::scene::primitive::cylinder::<unnamed>::make_cylinder");
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace primitive {
    
      // variables, exported

      /* static */ unsigned const cylinder::dflt_sides(36);
    
      // functions, exported

      /* explicit */
      cylinder::cylinder(unsigned a)
        : node::geometry(),
          sides         (*this, "sides", std::max(unsigned(3), a)) // TODO: make this an adapter
      {
        TRACE("hugh::scene::primitive::cylinder::cylinder");
      
        sides.touch();
      }
    
      /* virtual */ void
      cylinder::accept(visitor::base& v)
      {
        TRACE("hugh::scene::primitive::cylinder::accept");

        v.visit(*this);
      }

      /* virtual */ void
      cylinder::do_changed(field::base& f)
      {
        TRACE("hugh::scene::primitive::cylinder::do_changed");
      
        if (&f == &sides) {        
          make_cylinder(std::max(unsigned(3), *sides), attribute_list_, index_list_);
        
          compute_bounds();
          compute_tangents();
        }

        else {
          node::geometry::do_changed(f);
        }
      }
    
    } // namespace primitive {
  
  } // namespace scene {
  
} // namespace hugh {
