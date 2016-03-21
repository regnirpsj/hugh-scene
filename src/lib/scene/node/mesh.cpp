// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/mesh.cpp                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/mesh.hpp"

// includes, system

//#include <>

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
      mesh::mesh(attribute_list_type const& a, index_list_type const& b)
        : geometry()
      {
        TRACE("hugh::scene::node::mesh::mesh");

        attribute_list_ = a;
        index_list_     = b;

        compute_bounds();
        compute_normals();
        compute_tangents();
      }
    
      /* virtual */ void
      mesh::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::mesh::accept");

        v.visit(*this);
      }

      void
      mesh::compute_normals()
      {
        TRACE("hugh::scene::node::mesh::compute_normals");
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
