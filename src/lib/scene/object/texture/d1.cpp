// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/d1.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/texture/d1.hpp"

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
        d1::d1(unsigned const& a, glm::uvec4 const& b)
          : base  (),
            tdata_(gli::FORMAT_RGBA8_UNORM_PACK32, gli::texture1d::extent_type(a))
        {   
          TRACE("hugh::scene::object::d1::d1");
      
          fill(tdata_, glm::u8vec4(b));
        } 
    
        /* explicit */
        d1::d1(std::string const& a)
          : base  (),
            tdata_(load(a))
        {   
          TRACE("hugh::scene::object::d1::d1(file)");
      
          if (!empty()) {
            name = a;
          } 
        }
      
        /* virtual */
        d1::~d1()
        {
          TRACE("hugh::scene::object::d1::~d1");
        } 
    
        /* virtual */ bool
        d1::empty() const
        {
          TRACE("hugh::scene::object::d1::empty");
      
          return tdata_.empty();
        }

        /* virtual */ void
        d1::print_on(std::ostream& os) const
        {
          TRACE_NEVER("hugh::scene::object::d1::print_on");

          base::print_on(os);

          os << ','
             << tdata_
             << ']';
        }
      
      } // namespace texture {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
