// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/cylinder.cpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/cylinder.hpp"

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
  make_cylinder(unsigned                             /* sides */,
                geometry::base::attribute_list_type& /* attr_list */,
                geometry::base::index_list_type&     /* index_list */)
  {
    TRACE("hugh::scene::object::geometry::cylinder::<unnamed>::make_cylinder");
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // variables, exported

        /* static */ unsigned const cylinder::dflt_sides(36);
    
        // functions, exported

        /* explicit */
        cylinder::cylinder(unsigned a)
          : base (),
            sides(*this, "sides", std::max(unsigned(3), a)) // TODO: make this an adapter
        {
          TRACE("hugh::scene::object::geometry::cylinder::cylinder");
      
          sides.touch();
        }
    
        /* virtual */ void
        cylinder::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::geometry::cylinder::do_changed");
      
          if (&f == &sides) {        
            attribute_list_.clear();
            index_list_    .clear();
          
            make_cylinder(std::max(unsigned(3), *sides), attribute_list_, index_list_);
        
            compute_bounds();
            compute_tangents();
          }

          else {
            base::do_changed(f);
          }
        }

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {
  
} // namespace hugh {
