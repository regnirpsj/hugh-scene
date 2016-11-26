// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/rotor.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/rotor.hpp"

// includes, system

#include <glm/gtx/transform.hpp> // glm::rotate
#include <glm/gtx/io.hpp>        // glm::operator<<

// includes, project

#include <glm/gtx/utilities.hpp>
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
      rotor::rotor(float a, glm::vec3 const& b)
        : dynamic(),
          axis   (*this, "axis", glm::normalize(b)),
          rpm    (*this, "rpm",  a)
      {
        TRACE("hugh::scene::node::rotot::rotor");
      }
    
      /* virtual */ void
      rotor::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::rotot::accept");

        v.visit(*this);
      }
    
      /* virtual */ void
      rotor::do_changed(field::base& f)
      {
        TRACE("hugh::scene::node::rotot::do_changed");

        if ((&f == &update) ||
            (&f == &axis) ||
            (&f == &rpm)) {
          support::clock::time_point const now (update.get());
          support::clock::duration const   diff(now - last_update_);
        
          if (support::clock::resolution <= diff) {
#if defined(_MSC_VER) && (_MSC_VER < 1900)
            static float const full_circle(float(360 _deg));
#else
            static float const full_circle(float(360_deg));
#endif

            using namespace std::chrono;

            //                              (rpm -> sec -> msec -> usec)
            float const angle(full_circle * (rpm.get() / 60.0f / 1000.0f / 1000.0f) *
                              duration_cast<microseconds>(diff).count());

            xform.set(xform.get() * glm::rotate(angle, axis.get()));
        
#if 0
            {    
              std::cout << support::trace::prefix() << "hugh::scene::node::rotor::update: "
                        << "d_time: "   << duration_cast<microseconds>(diff).count() << "us, "
                        << "d_angle:"   << angle                                     << ", "
                        << "xform acc:" << xform
                        << std::endl;
            }
#endif

            invalidate_bounds();

            last_update_ = now;
          }
        }

        else {
          dynamic::do_changed(f);
        }
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
