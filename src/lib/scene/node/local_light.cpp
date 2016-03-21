// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/local_light.cpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/local_light.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/light/positional.hpp>
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
      local_light::local_light()
        : group (),
          source(*this, "source", new object::light::positional)
      {
        TRACE("hugh::scene::node::local_light::local_light");
      }
    
      /* virtual */ void
      local_light::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::local_light::accept");

        v.visit(*this);
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
