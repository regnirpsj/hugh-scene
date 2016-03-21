// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/bfs.cpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/bfs.hpp"

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

  template <typename L, typename T, typename Q>
  inline void
  visit_helper(L const& l, T const*, Q& q, hugh::scene::visitor::bfs& v)
  {
    TRACE("hugh::scene::visitor::bfs::<unnamed>::visit_helper(" +
          hugh::support::demangle(typeid(l)) + ")");

    Q lq;

    for (auto const& c : l) {
      if (nullptr == dynamic_cast<T const*>(c.get())) {
        q.push(c);
      } else {
        lq.push(c);
      }
    }

    while (!lq.empty()) {
      lq.front()->accept(v);
      lq.pop();
    }
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // variables, exported
  
      // functions, exported

      /* virtual */
      bfs::~bfs()
      {
        TRACE("hugh::scene::visitor::bfs::~bfs");

        flush();
      }
    
      /* virtual */ void
      bfs::visit(node::group& a)
      {
        TRACE("hugh::scene::visitor::bfs::visit(node::group)");

        visit_helper(a.children.get(), &a, node_queue_, *this);
      }

      /* virtual */ void
      bfs::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::visitor::bfs::print_on");

        os << '['
           << "hugh::scene::visitor::bfs"
           << ']';
      }

      /* explicit */
      bfs::bfs()
        : base       (),
          node_queue_()
      {
        TRACE("hugh::scene::visitor::bfs::bfs");
      }

      /* virtual */ void
      bfs::flush()
      {
        TRACE("hugh::scene::visitor::bfs::flush");
      
        while (!node_queue_.empty()) {
          node_queue_.front()->accept(*this);
          node_queue_.pop();
        }
      }

      /* virtual */ void
      bfs::visit(subject&)
      {
        TRACE("hugh::scene::visitor::bfs::visit(subject)");
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
