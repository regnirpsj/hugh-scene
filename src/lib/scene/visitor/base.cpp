// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/base.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <stdexcept>      // std::logic_error

// includes, project

#include <hugh/scene/nodes.hpp>
#include <hugh/scene/visitor/subject.hpp>

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

    namespace visitor {
    
      // variables, exported
  
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("hugh::scene::visitor::base::~base");
      }

      /* virtual */ void
      base::visit(node::base& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::base)");
      
        visit_base(a);
      }
    
      /* virtual */ void
      base::visit(node::camera& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::camera)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::dynamic& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::dynamic)");

        visit_base(a);
      }
    
      /* virtual */ void
      base::visit(node::geometry& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::geometry)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::global_light& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::global_light)");

        visit_base(a);
      }
    
      /* virtual */ void
      base::visit(node::group& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::group)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::local_light& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::local_light)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::material_group& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::material_group)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::rotor& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::rotor)");

        visit_base(a);
      }
    
      /* virtual */ void
      base::visit(node::select& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::select)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::transform& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::transform)");

        visit_base(a);
      }

      /* virtual */ void
      base::visit(node::translator& a)
      {
        TRACE("hugh::scene::visitor::base::visit(node::translator)");

        visit_base(a);
      }

      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::visitor::base::print_on");

        os << '['
           << "hugh::scene::visitor::base"
           << ']';
      }

      /* explicit */
      base::base()
        : support::printable()
      {
        TRACE("hugh::scene::visitor::base::base");
      }
    
      /* virtual */ void
      base::visit(subject&)
      {
        TRACE("hugh::scene::visitor::base::visit(subject)");
      
        throw std::logic_error("pure virtual function "
                               "'hugh::scene::visitor::base::visit(subject)' called");
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
