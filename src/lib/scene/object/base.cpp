// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/base.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/base.hpp"

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
    
      // variables, exported
  
      // functions, exported

      /* virtual */
      base::~base()
      {
        TRACE("hugh::scene::object::base::~base");
      }
    
      /* virtual */ void
      base::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::object::base::print_on");

        os << '[';
      
        field::container::print_on(os);

        os << ','
           << "rc:" << use_count()
           << ']';
      }
    
      /* explicit */
      base::base()
        : field::container         (),
          support::refcounted<base>(),
          name                     (*this, "name", "")
      {
        TRACE("hugh::scene::object::base::base");
      }
    
      /* virtual */ void
      base::do_changed(field::base& f)
      {
        TRACE("hugh::scene::object::base::do_changed");

        if (&f == &name) {
          // nothing to do
        }

        else {
          field::container::do_changed(f);
        }
      }
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
