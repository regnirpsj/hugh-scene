// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/transform.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/transform.hpp"

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
      transform::transform(glm::mat4 const& a)
        : group(),
          xform(*this, "xform", a)
      {
        TRACE("hugh::scene::node::transform::transform");
      }
    
      /* virtual */ void
      transform::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::transform::accept");

        v.visit(*this);
      }

      /* virtual */ glm::mat4
      transform::absolute_xform() const
      {
        TRACE("hugh::scene::node::transform::absolute_xform");

        glm::mat4 result(xform.get());
      
        if (nullptr != parent_) {
          result = parent_->absolute_xform() * result;
        } 

        return result;
      }

      /* virtual */ void
      transform::do_changed(field::base& f)
      {
        TRACE("hugh::scene::node::transform::do_changed");

        if      (&f == &xform) {
          invalidate_bounds();
        }

        else {
          group::do_changed(f);
        }
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
