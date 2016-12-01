// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/material/base.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/material/base.hpp"

// includes, system

//#include <>

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
    
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::scene::object::material::base::~base");
        }

        /* explicit */
        base::base()
          : object::base()
        {
          TRACE("hugh::scene::object::material::base::base");

          bbox = object::base::bounds::null;
        }
        
      } // namespace material {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
