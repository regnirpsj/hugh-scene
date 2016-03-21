// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/print.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/visitor/print.hpp"

// includes, system

#include <boost/io/ios_state.hpp> // boost::io::ios_all_saver
#include <ostream>                // std::ostream

// includes, project

#include <hugh/scene/node/base.hpp>
#include <hugh/scene/node/geometry.hpp>
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

  char const dflt_crlf('\n');
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // variables, exported
  
      // functions, exported

      /* explicit */
      print::print(std::ostream& a, order b)
        : bfs    (),
          dfs    (),
          os_    (a),
          order_ (b),
          indent_(0),
          crlf_  (dflt_crlf)
      {
        TRACE("hugh::scene::visitor::print::print");
      }
    
      /* virtual */
      print::~print()
      {
        TRACE("hugh::scene::visitor::print::~print");

        switch (order_) {
        case order::bfs:
          {
            flush();
          }
          break;
      
        default:
          break;
        }
      }
    
      /* virtual */ void
      print::visit(node::base& a)
      {
        TRACE("hugh::scene::visitor::print::visit(node::base)");

        boost::io::ios_all_saver const ias(os_);
      
        os_ << std::string((2 * indent_), ' ')
            << a
            << crlf_;
      }
    
      /* virtual */ void
      print::visit(node::group& a)
      {
        TRACE("hugh::scene::visitor::print::visit(node::group)");

        visit_helper(a);
      }

      /* virtual */ void
      print::print_on(std::ostream& os) const
      {
        TRACE_NEVER("hugh::scene::visitor::print::print_on");

        os << '[';
      
        switch (order_) {
        case order::bfs:
          os << "bfs";
          break;

        case order::dfs:
          os << "dfs";
          break;
        }
      
        os << ']';
      }

      /* virtual */ void
      print::visit(subject&)
      {
        TRACE("hugh::scene::visitor::print::visit(subject)");
      }
    
      template <typename T>
      void
      print::visit_helper(T& t)
      {
        TRACE("hugh::scene::visitor::print::visit_helper(" + support::demangle(typeid(t)) + ")");

        visit(static_cast<node::base&>(t));
    
        switch (order_) {
        case order::bfs:
          {
            bfs::visit(t);
          }
          break;

        case order::dfs:
          {
            ++indent_;
            {
              dfs::visit(t);
            }
            --indent_;
          }
          break;
        }
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {
