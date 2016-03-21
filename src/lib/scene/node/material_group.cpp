// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/material_group.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/material_group.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

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
      material_group::material_group()
        : group   (),
          material(*this, "material", new object::material)
      {
        TRACE("hugh::scene::node::material_group::material_group");
      }
    
      /* virtual */ void
      material_group::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::material_group::accept");

        v.visit(*this);
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
