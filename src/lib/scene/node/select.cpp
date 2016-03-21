// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/select.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/select.hpp"

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
      select::select()
        : group(),
          index(*this, "index", 0)
      {
        TRACE("hugh::scene::node::select::select");
      }
    
      /* virtual */ void
      select::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::select::accept");

        v.visit(*this);
      }

      /* virtual */ void
      select::do_changed(field::base& f)
      {
        TRACE("hugh::scene::object::select::do_changed");

        if (&f == &index) {
          // nothing to do
        }

        else {
          group::do_changed(f);
        }
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
