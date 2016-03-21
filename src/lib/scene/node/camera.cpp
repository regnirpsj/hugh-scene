// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/camera.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/camera.hpp"

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
      camera::camera(object::camera::base* a)
        : base  (),
          object(*this, "object", a),
          view  (*this, "view",
                 std::bind(&camera::cb_get_view, this),
                 std::bind(&camera::cb_set_view, this, std::placeholders::_1)),
          inverse_view_()
      {
        TRACE("hugh::scene::node::camera::camera");

        bbox = bounds(glm::vec3(0,0,0), glm::vec3(0,0,0), true);
      }
    
      /* virtual */ void
      camera::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::camera::accept");

        v.visit(*this);
      }
    
      glm::mat4 const&
      camera::cb_get_view() const
      {
        TRACE("hugh::scene::node::camera::cb_get_view");

        inverse_view_ = glm::inverse(absolute_xform());
      
        return inverse_view_;
      }
    
      glm::mat4
      camera::cb_set_view(glm::mat4 const&)
      {
        TRACE("hugh::scene::node::camera::cb_set_view");

        return cb_get_view();
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
