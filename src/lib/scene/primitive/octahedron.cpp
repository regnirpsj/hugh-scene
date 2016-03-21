// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/octahedron.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/primitive/octahedron.hpp"

// includes, system

#include <array> // std::array<>

// includes, project

#include <hugh/scene/visitor/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  using namespace hugh::scene;
  
  // variables, internal
  
  // functions, internal

  void
  make_octahedron(node::geometry::attribute_list_type& attr_list,
                  node::geometry::index_list_type&     index_list)
  {
    TRACE("hugh::scene::primitive::octahedron::<unnamed>::make_octahedron");
    
    // right-handed coordinate system assumed
    static std::array<glm::vec3, 6> const points = {
      {
        glm::vec3(-0.5,  0.0,  0.0),
        glm::vec3( 0.0,  0.0,  0.5),
        glm::vec3( 0.5,  0.0,  0.0),
        glm::vec3( 0.0,  0.0, -0.5),
        glm::vec3( 0.0,  0.5,  0.0),
        glm::vec3( 0.0, -0.5,  0.0),
      }
    };

    static std::array<std::array<float, 2>, 3> const tcoords = {
      {
        { { 0.0, 0.0 } },
        { { 1.0, 0.0 } },
        { { 0.5, 0.5 } },
      }
    };
    
    static std::array<std::array<unsigned, 3>, 8> const indices = {
      {
        // i_p1, i_p2, i_p3
        { { 0, 1, 4 } },
        { { 4, 1, 2 } },
        { { 2, 3, 4 } },
        { { 4, 3, 0 } },
        { { 0, 3, 5 } },
        { { 5, 3, 2 } },
        { { 2, 1, 5 } },
        { { 5, 1, 0 } },
      }
    };
    
    unsigned idx_count(0);

    for (auto const& idx : indices) {
      glm::vec3 const& p1(points[idx[0]]);
      glm::vec3 const& p2(points[idx[1]]);
      glm::vec3 const& p3(points[idx[2]]);
      glm::vec3 const  n (glm::normalize(glm::cross(p1 - p2, p3 - p2)));

      using node::geometry;
      
      attr_list.push_back(geometry::attribute(p1, n, glm::vec2(tcoords[0][0], tcoords[0][1])));
      attr_list.push_back(geometry::attribute(p2, n, glm::vec2(tcoords[1][0], tcoords[1][1])));
      attr_list.push_back(geometry::attribute(p3, n, glm::vec2(tcoords[2][0], tcoords[2][1])));

      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
    }
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace primitive {
    
      // variables, exported
    
      // functions, exported

      /* explicit */
      octahedron::octahedron()
        : node::geometry()
      {
        TRACE("hugh::scene::primitive::octahedron::octahedron");

        make_octahedron(attribute_list_, index_list_);
      
        compute_bounds();
        compute_tangents();
      }
    
      /* virtual */ void
      octahedron::accept(visitor::base& v)
      {
        TRACE("hugh::scene::primitive::octahedron::accept");

        v.visit(*this);
      }
    
    } // namespace primitive {
  
  } // namespace scene {

} // namespace hugh {
