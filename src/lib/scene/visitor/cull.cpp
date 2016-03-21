// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/cull.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/cull.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*
#include <ostream>        // std::ostream

// includes, project

#include <hugh/scene/node/camera.hpp>
#include <hugh/scene/node/geometry.hpp>
#include <hugh/scene/node/group.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  bool
  visible(hugh::scene::node::camera const& a, hugh::scene::node::base const& b)
  {
    TRACE("hugh::scene::visitor::cull::<unnamed>::visible");
    
    auto const& mvp    (a.object.get()->projection.get() * a.view.get() * b.absolute_xform());
    auto const& frustum(a.object.get()->frustum.get());
    bool        result(true);
    
    if (!frustum.contains(glm::vec3(mvp * glm::vec4(b.bbox.get().min, 1)).xyz()) &&
        !frustum.contains(glm::vec3(mvp * glm::vec4(b.bbox.get().max, 1)).xyz())) {
      result = false;
    }
    
    return result;
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace visitor {

      // variables, exported
  
      // functions, exported

      /* explicit */
      cull::cull(node::camera const& a, visible_list_type& b)
        : dfs          (),
          camera_      (a),
          visible_list_(b)
      {
        TRACE("hugh::scene::visitor::cull::cull");

        visible_list_.clear();
      }
    
      /* virtual */
      cull::~cull()
      {
        TRACE("hugh::scene::visitor::cull::~cull");
      }
    
      /* virtual */ void
      cull::visit(node::geometry& a)
      {
        TRACE("hugh::scene::visitor::cull::visit(node::geometry)");

        if (visible(camera_, a)) {
          visible_list_.insert(&a);
        }
      }
    
      /* virtual */ void
      cull::visit(node::group& a)
      {
        TRACE("hugh::scene::visitor::cull::visit(node::group)");

        if (visible(camera_, a)) {
          dfs::visit(a);
        }
      }
    
      /* virtual */ void
      cull::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::visitor::cull::print_on");

        os << '['
           << "hugh::scene::visitor::cull"
           << ']';
      }
          
      /* virtual */ void
      cull::visit(subject&)
      {
        TRACE("hugh::scene::visitor::cull::visit(subject)");
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
