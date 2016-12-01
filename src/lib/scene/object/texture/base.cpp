// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/base.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/texture/base.hpp"

// includes, system

#include <stdexcept> // std::logic_error

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  glm::uvec3 const dflt_size (1, 1, 1);
  glm::uvec4 const dflt_color(1, 1, 1, 1);
  
  // functions, internal
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
      
        // variables, exported
        
        /* static */ glm::uvec3 const base::default_size (dflt_size);
        /* static */ glm::uvec4 const base::default_color(dflt_color);
    
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::scene::object::base::~base");
        }
    
        /* explicit */
        base::base()
          : object::base()
        {
          TRACE("hugh::scene::object::base::base");

          bbox = object::base::bounds::null;
        }

        /* virtual */ bool
        base::empty() const
        {
          TRACE("hugh::scene::object::base::empty");

          throw std::logic_error("pure virtual function 'hugh::scene::object::base::empty' called");

          return false;
        }

      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
