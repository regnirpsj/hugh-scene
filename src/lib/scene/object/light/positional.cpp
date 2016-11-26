// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/positional.cpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/light/positional.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  hugh::scene::object::light::base::rep const dflt_rep(false,
                                                       glm::vec4(0.0, 0.0,  1.0, 1.0),
                                                       glm::vec3(0.0, 0.0, -1.0),
                                                       glm::vec3(0.0, 0.0,  0.0),
                                                       glm::vec3(1.0, 1.0,  1.0),
                                                       glm::vec3(1.0, 1.0,  1.0),
                                                       glm::vec3(1.0, 0.0,  0.0),
                                                       0.0,
                                                       glm::radians(180.0f));
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // variables, exported

        /* static */ positional const positional::dflt_light;
    
        // functions, exported
    
        /* explicit */
        positional::positional()
          : base    (dflt_rep),
            position(*this, "position", dflt_rep.position.xyz())
        {   
          TRACE("hugh::scene::object::light::positional::positional");
        }
      
        /* virtual */ void
        positional::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::light::positional::changed");
        
          if (&f == &position) { rep_list_[0].position.xyz() = position.get(); }
        
          else {
            base::do_changed(f);
          }
        }

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
