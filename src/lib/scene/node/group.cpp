// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/group.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/group.hpp"

// includes, system

#include <algorithm> // std::find<>
#include <stdexcept> // std::runtime_error

// includes, project

#include <hugh/scene/visitor/base.hpp>

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

    namespace node {
    
      // variables, exported
    
      // functions, exported

      /* explicit */
      group::group()
        : base          (),
          children      (*this, "children",
                         std::bind(&group::cb_get_children, this),
                         std::bind(&group::cb_set_children, this, std::placeholders::_1),
                         std::bind(&group::cb_add_child,    this, std::placeholders::_1),
                         std::bind(&group::cb_sub_child,    this, std::placeholders::_1)),
          children_list_()
      {
        TRACE("hugh::scene::node::group::group");
      }

      /* virtual */
      group::~group()
      {
        TRACE("hugh::scene::node::group::~group");
      }
    
      /* virtual */ void
      group::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::group::accept");

        v.visit(*this);
      }

      group::children_list_type const&
      group::cb_get_children() const
      {
        TRACE("hugh::scene::node::group::cb_get_children");

        return children_list_;
      }

      group::children_list_type
      group::cb_set_children(children_list_type const& a)
      {
        TRACE("hugh::scene::node::group::cb_set_children");

        children_list_type result(children_list_);

        for (auto const& c : result) {
          cb_sub_child(c);
        }
      
        for (auto const& c : a) {
          cb_add_child(c);
        }
      
        return result;
      }

      bool
      group::cb_add_child(children_type const& a)
      {
        TRACE("hugh::scene::node::group::cb_add_child");

        bool result(false);

        if (nullptr != a) {
          if (this != a.get()) {
            auto const found(std::find(children_list_.begin(), children_list_.end(), a));

            if (children_list_.end() == found) {
              children_list_.insert(children_list_.end(), a);
              {
                group* p(dynamic_cast<group*>(a->parent_));
          
                if (nullptr != p) {
                  p->cb_sub_child(a);
                }
              }
              a->parent_ = this;

              invalidate_bounds();
        
              result = true;
            }
          } else {
            throw std::runtime_error("'hugh::scene::node::group::cb_add_child': "
                                     "adding a 'scene::node::group' instance to its own 'children' "
                                     "field is not supported");
          }
        }
      
        return result;
      }

      bool
      group::cb_sub_child(children_type const& a)
      {
        TRACE("hugh::scene::node::group::cb_sub_child");

        bool result(false);

        if (nullptr != a) {
          auto const found(std::find(children_list_.begin(), children_list_.end(), a));

          if (children_list_.end() != found) {          
            a->parent_ = nullptr;
          
            children_list_.erase(found);

            invalidate_bounds();
        
            result = true;
          }
        }
      
        return result;
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
