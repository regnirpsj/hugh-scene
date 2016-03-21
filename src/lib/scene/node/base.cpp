// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/base.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

// includes, project

#include <glm/gtx/limits.hpp>

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

      /* static */ base::bounds const base::bounds::invalid
      (
       glm::vec3(+std::numeric_limits<glm::vec3>::infinity(),
                 +std::numeric_limits<glm::vec3>::infinity(),
                 +std::numeric_limits<glm::vec3>::infinity()),
       glm::vec3(-std::numeric_limits<glm::vec3>::infinity(),
                 -std::numeric_limits<glm::vec3>::infinity(),
                 -std::numeric_limits<glm::vec3>::infinity()),
       false // invalid
       );
    
      // functions, exported

      /* explicit */
      base::bounds::bounds(glm::vec3 const& a, glm::vec3 const& b, bool c)
        : min(a), max(b), valid(c)
      { 
        TRACE("hugh::scene::node::base::bounds::bounds");
      } 
    
      /* virtual */
      base::~base()
      {
        TRACE("hugh::scene::node::base::~base");
      }

      /* virtual */ void
      base::accept(visitor::base&)
      {
        TRACE("hugh::scene::node::base::accept");

        throw std::logic_error("pure virtual function 'hugh::scene::node::base::accept' called");
      }

      /* virtual */ glm::mat4
      base::absolute_parent_xform() const
      {
        TRACE("hugh::scene::node::base::absolute_parent_xform");
    
        glm::mat4 result(1);
    
        if (nullptr != parent_) {
          result = parent_->absolute_xform();
        }
    
        return result;
      }

      /* virtual */ glm::mat4
      base::absolute_xform() const
      {
        TRACE("hugh::scene::node::base::absolute_xform");
      
        return absolute_parent_xform();
      }

      /* explicit */
      base::base()
        : object::base    (),
          visitor::subject(),
          parent          (*this, "parent",
                           std::bind(&base::cb_get_parent, this),
                           std::bind(&base::cb_set_parent, this, std::placeholders::_1)),
          travmask        (*this, "travmask", static_cast<unsigned>(~0)),
          bbox            (*this, "bbox",     bounds::invalid),
          parent_         (nullptr)
      {
        TRACE("hugh::scene::node::base::base");
      }

      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("hugh::scene::node::base::do_changed");

        if      (&f == &parent) {
          // nothing to do
        }

        else if ((&f == &travmask) ||
                 (&f == &bbox)) {
          if (nullptr != parent_) {
            parent_->invalidate_bounds();
          }
        }

        else {
          object::base::do_changed(f);
        }
      }

      /* virtual */ void
      base::invalidate_bounds()
      {
        TRACE("hugh::scene::node::base::invalidate_bounds");

        if (bbox.get().valid) {
          bbox = bounds(bbox.get().min, bbox.get().max, false);

          if (nullptr != parent_) {
            parent_->invalidate_bounds();
          }
        }
      }

      base::parent_type const&
      base::cb_get_parent() const
      {
        TRACE("hugh::scene::node::base::cb_get_parent");

        return parent_;
      }

      base::parent_type
      base::cb_set_parent(base::parent_type const&)
      {
        TRACE("hugh::scene::node::base::cb_set_parent");

        // nothing to do; 'parent_' bookkeeping is internally handled
      
        return cb_get_parent();
      }

      std::ostream&
      operator<<(std::ostream& os, base::bounds const& a)
      {
        TRACE_NEVER("hugh::scene::node::operator<<(scene::node::base::bounds)");

        std::ostream::sentry const cerberus(os);

        if (cerberus) {
          glm::io::format_saver const iofs(os);

          os << glm::io::precision(2) << glm::io::width(4)
             << '['
             << a.min                  << ','
             << a.max                  << ','
             << ((a.valid) ? "" : "!") << "valid"
             << ']';
        }

        return os;
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
