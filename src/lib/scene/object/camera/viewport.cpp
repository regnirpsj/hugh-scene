// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/viewport.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/camera/viewport.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

//#include <>

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

      namespace camera {
      
        // variables, exported
    
        // functions, exported

        /* explicit */
        viewport::viewport(float a, float b, float c, float d, float e, float f)
          : x(a), y(b), width(c), height(d), near(e), far(f)
        {
          TRACE("hugh::scene::object::camera::viewport::viewport");
        }
      
        std::ostream&
        operator<<(std::ostream& os, viewport const& a)
        {
          TRACE_NEVER("hugh::scene::object::camera::operator<<(viewport)");

          std::ostream::sentry const cerberus(os);

          if (cerberus) {
            os << '['
               << "x:"  << a.x      << ','
               << "y:"  << a.y      << ','
               << "w:"  << a.width  << ','
               << "h:"  << a.height << ','
               << "d:[" << a.near   << ',' << a.far << ']'
               << ']';
          }

          return os;
        }
      
      } // namespace camera {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
