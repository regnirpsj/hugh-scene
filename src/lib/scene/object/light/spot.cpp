// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/spot.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/light/spot.hpp"

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

        /* static */ spot const spot::dflt_light;
    
        // functions, exported
    
        /* explicit */
        spot::spot()
          : base       (dflt_rep),
            directional(),
            positional (),
            exponent   (*this, "exponent", dflt_rep.exponent),
            cutoff     (*this, "cutoff",   dflt_rep.cutoff)
        {   
          TRACE("hugh::scene::object::light::spot::spot");
        }
    
        /* virtual */ void
        spot::do_evaluate()
        {
          TRACE("hugh::scene::object::light::spot::do_evaluate");
        
          directional::do_evaluate();
          positional::do_evaluate();
        }
      
        /* virtual */ void
        spot::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::light::spot::do_changed");
        
          if      (&f == &exponent) { rep_list_[0].exponent = exponent.get(); }
          else if (&f == &cutoff)   { rep_list_[0].cutoff   = cutoff.get();   }
        
          else {
            directional::do_changed(f);
            positional::do_changed(f);
          }
        }

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
