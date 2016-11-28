// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/attribute.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/attribute.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

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

      namespace geometry {
        
        // variables, exported
    
        // functions, exported

        /* explicit */
        attribute::attribute(glm::vec3 const& a, glm::vec3 const& b, glm::vec2 const& c,
                             glm::vec4 const& d, glm::vec4 const& e)
          : position(a), normal(b), tcoord(c), tangent(d), color(e)
        {
          TRACE("hugh::scene::object::attribute::attribute");
        }
    
        std::ostream&
        operator<<(std::ostream& os, attribute const& a)
        {
          TRACE_NEVER("hugh::scene::object::operator<<(attribute)");
      
          std::ostream::sentry const cerberus(os);

          if (cerberus) {
            glm::io::format_saver const iofs(os);

            os << glm::io::precision(2)
               << glm::io::width(1 + 2 + 1 + unsigned(os.precision()))
               << '['
               << "v:"  << a.position << ','
               << "n:"  << a.normal   << ','
               << "tc:" << a.tcoord   << ','
               << "t:"  << a.tangent  << ','
               << "c:"  << a.color
               << ']';
          }

          return os;
        }

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
