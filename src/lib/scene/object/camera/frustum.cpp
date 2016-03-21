// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/frustum.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/camera/frustum.hpp"

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
        frustum::frustum(float a, float b, float c, float d, float e, float f)
          : left(a), right(b), bottom(c), top(d), near(e), far(f)
        { 
          TRACE("hugh::scene::object::camera::frustum::frustum");
        }

        bool
        frustum::contains(glm::vec3 const& a) const
        {
          TRACE("hugh::scene::object::camera::frustum::contains");

          return ((  left <= a.x) && (right >= a.x) &&
                  (bottom <= a.y) && (  top >= a.y) &&
                  (  near <= a.z) && (  far >= a.z));
        }

        std::ostream&
        operator<<(std::ostream& os, frustum const& a)
        {
          TRACE_NEVER("hugh::scene::object::camera::operator<<(frustum)");
        
          std::ostream::sentry const cerberus(os);

          if (cerberus) {
            os << '['
               << "l:" << a.left   << ','
               << "r:" << a.right  << ','
               << "b:" << a.bottom << ','
               << "t:" << a.top    << ','
               << "n:" << a.near   << ','
               << "f:" << a.far
               << ']'; 
          }

          return os;
        }
      
      } // namespace camera {
    
    } // namespace object {
  
  } // namespace scene {
  
} // namespace hugh {
