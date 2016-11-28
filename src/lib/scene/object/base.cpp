// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/base.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/base.hpp"

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

    namespace object {
    
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
        TRACE("hugh::scene::object::base::bounds::bounds");
      } 

      /* virtual */
      base::~base()
      {
        TRACE("hugh::scene::object::base::~base");
      }
    
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::object::base::print_on");

        os << '[';
      
        field::container::print_on(os);

        os << ','
           << "rc:" << use_count()
           << ']';
      }
    
      /* explicit */
      base::base()
        : field::container         (),
          support::refcounted<base>(),
          name                     (*this, "name", ""),
          bbox                     (*this, "bbox", bounds::invalid)
      {
        TRACE("hugh::scene::object::base::base");
      }
    
      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("hugh::scene::object::base::do_changed");

        if      (&f == &name) {
          // nothing to do
        }
        
        else if (&f == &bbox) {
          // nothing to do
        }
        
        else {
          field::container::do_changed(f);
        }
      }
    
      /* virtual */ void
      base::invalidate_bounds()
      {
        TRACE("hugh::scene::object::base::invalidate_bounds");

        if (bbox.get().valid) {
          bbox = bounds(bbox.get().min, bbox.get().max, false);
        }
      }

      std::ostream&
      operator<<(std::ostream& os, base::bounds const& a)
      {
        TRACE_NEVER("hugh::scene::object::operator<<(scene::object::base::bounds)");

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

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
