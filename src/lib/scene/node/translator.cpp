// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/translator.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/translator.hpp"

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
      translator::translator(glm::vec3 const& a)
        : dynamic  (),
          direction(*this, "direction", glm::normalize(a)),
          speed    (*this, "speed",     glm::length(a))
      {
        TRACE("hugh::scene::node::translator::translator(glm::vec3)");
      }
    
      /* explicit */
      translator::translator(float a, glm::vec3 const& b)
        : dynamic  (),
          direction(*this, "direction", glm::normalize(b)),
          speed    (*this, "speed",     a)
      {
        TRACE("hugh::scene::node::translator::translator(float,glm::vec3)");
      }

      /* virtual */ void
      translator::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::translator::accept");

        v.visit(*this);
      }

      /* virtual */ void
      translator::do_changed(field::base& f)
      {
        TRACE("hugh::scene::node::translator::");

        if      (&f == &direction) {
        }

        else if (&f == &speed) {
        }

        else {
          dynamic::do_changed(f);
        }
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
