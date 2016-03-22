// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/d3.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/texture/d3.hpp"

// includes, system

#include <ostream> // std::ostream

// includes, project

#include <gli/gtx/io.hpp>
#include <object/texture/fill.hpp>
#include <object/texture/load.hpp>

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

      namespace texture {
  
        // variables, exported
  
        // functions, exported

        /* explicit */
        d3::d3(glm::uvec3 const& a, glm::uvec4 const& b)
          : base  (),
            tdata_(gli::FORMAT_RGBA8_UNORM_PACK32, gli::texture3d::extent_type(a.x, a.y, a.z))
        {   
          TRACE("hugh::scene::object::d3::d3");
      
          fill(tdata_, glm::u8vec4(b));
        } 
    
        /* explicit */
        d3::d3(std::string const& a)
          : base  (),
            tdata_(load(a))
        {   
          TRACE("hugh::scene::object::d3::d3(file)");
      
          if (!empty()) {
            name = a;
          } 
        }
      
        /* virtual */
        d3::~d3()
        {
          TRACE("hugh::scene::object::d3::~d3");
        } 
    
        /* virtual */ bool
        d3::empty() const
        {
          TRACE("hugh::scene::object::d3::empty");
      
          return tdata_.empty();
        }
      
        /* virtual */ void
        d3::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::scene::object::d3::print_on");

          base::print_on(os);

          os << ','
             << tdata_
             << ']';
        }

      } // namespace texture {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
