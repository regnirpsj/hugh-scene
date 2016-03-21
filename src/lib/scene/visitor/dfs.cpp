// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/dfs.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/dfs.hpp"

// includes, system

#include <string> // std::string

// includes, project

#include <hugh/scene/node/group.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

  template <typename L>
  inline void
  visit_helper(L const& l, hugh::scene::visitor::dfs& v)
  {
    TRACE("hugh::scene::visitor::dfs::<unnamed>::visit_helper(" +
          hugh::support::demangle(typeid(l)) + ")");

    for (auto& c : l) {
      c->accept(v);
    }
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // variables, exported
  
      // functions, exported

      /* virtual */
      dfs::~dfs()
      {
        TRACE("hugh::scene::visitor::dfs::~dfs");
      }

      /* virtual */ void
      dfs::visit(node::group& a)
      {
        TRACE("hugh::scene::visitor::dfs::visit(node::group)");

        visit_helper(a.children.get(), *this);
      }

      /* virtual */ void
      dfs::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::visitor::dfs::print_on");

        os << '['
           << "hugh::scene::visitor::dfs"
           << ']';
      }

      /* explicit */
      dfs::dfs()
        : base()
      {
        TRACE("hugh::scene::visitor::dfs::dfs");
      }

      /* virtual */ void
      dfs::visit(subject&)
      {
        TRACE("hugh::scene::visitor::dfs::visit(subject)");
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
