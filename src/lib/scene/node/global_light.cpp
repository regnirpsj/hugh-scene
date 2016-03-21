// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/global_light.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/global_light.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/light/area.hpp>
#include <hugh/scene/object/light/directional.hpp>
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
      global_light::global_light()
        : base  (),
          source(*this, "source", new object::light::directional)
      {
        TRACE("hugh::scene::node::global_light::global_light");
      }
    
      /* virtual */ void
      global_light::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::global_light::accept");

        v.visit(*this);
      }

      /* virtual */ void
      global_light::do_changed(field::base& f)
      {
        TRACE("hugh::scene::node::global_light::do_changed");

        if (&f == &source) {
          object::light::area* const al(dynamic_cast<object::light::area*>(source.get().get()));
        
          if (nullptr != al) {
            glm::vec2 const xy(glm::vec2(al->size.get()) * 0.5f);
          
            bbox = bounds(glm::vec3(-xy,0), glm::vec3( xy,0), true);
          } else {
            bbox = bounds(glm::vec3(0,0,0), glm::vec3(0,0,0), true);
          }
        }

        else {
          base::do_changed(f);
        }
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
