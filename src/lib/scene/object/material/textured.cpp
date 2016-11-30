// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/material/textured.cpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/material/textured.hpp"

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
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace material {
        
        // variables, exported

        /* static */ textured const   textured::dflt_material;
        /* static */ glm::uvec2 const textured::dflt_tex_size (1, 1);
        /* static */ glm::uvec4 const textured::dflt_tex_black(0);
        /* static */ glm::uvec4 const textured::dflt_tex_white(1);

        // functions, exported

        /* explicit */
        textured::textured(simple::rep const& a,
                           texture_type* b, texture_type* c, texture_type* d, texture_type* e)
          : simple  (a),
            ambient (*this, "ambient",  b),
            diffuse (*this, "diffuse",  c),
            emission(*this, "emission", d),
            specular(*this, "specular", e)
        {
          TRACE("hugh::scene::object::material::textured::textured");
        }
        
      } // namespace material {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
