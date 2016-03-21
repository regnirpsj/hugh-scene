// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/subject.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/subject.hpp"

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
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // variables, exported
  
      // functions, exported

      /* virtual */
      subject::~subject()
      {
        TRACE("hugh::scene::visitor::subject::~subject");
      }

      /* virtual */ void
      subject::accept(visitor::base&)
      {
        TRACE("hugh::scene::visitor::subject::accept");

        throw std::logic_error("pure virtual function "
                               "'hugh::scene::visitor::subject::accept' called");
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
