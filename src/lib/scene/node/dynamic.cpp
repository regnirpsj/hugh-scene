// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/dynamic.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/dynamic.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/visitor/base.hpp>
#include <hugh/support/chrono_io.hpp>

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

      /* virtual */
      dynamic::~dynamic()
      {
        TRACE("hugh::scene::node::dynamic::~dynamic");
      }
    
      /* virtual */ void
      dynamic::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::dynamic::accept");

        v.visit(*this);
      }
    
      /* explicit */
      dynamic::dynamic()
        : transform   (),
          update      (*this, "update", support::clock::now()),
          last_update_(update.get())
      {
        TRACE("hugh::scene::node::dynamic::dynamic");
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
