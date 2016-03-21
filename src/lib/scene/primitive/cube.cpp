// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/primitive/cube.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/primitive/cube.hpp"

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
  make_cube(node::geometry::attribute_list_type& attr_list,
            node::geometry::index_list_type&     index_list)
  {
    TRACE("hugh::scene::primitive::cube::<unnamed>::make_cube");
    
    // left-handed coordinate system assumed
    static std::array<glm::vec3, 8> const points = {
      {
        glm::vec3(-0.5, -0.5,  0.5),
        glm::vec3( 0.5, -0.5,  0.5),
        glm::vec3( 0.5,  0.5,  0.5),
        glm::vec3(-0.5,  0.5,  0.5),
        glm::vec3(-0.5, -0.5, -0.5),
        glm::vec3( 0.5, -0.5, -0.5),
        glm::vec3( 0.5,  0.5, -0.5),
        glm::vec3(-0.5,  0.5, -0.5),
      }
    };

    static std::array<std::array<float, 2>, 4> const tcoords = {
      {
        { { 0.0, 0.0 } }, // ll
        { { 1.0, 0.0 } }, // lr
        { { 1.0, 1.0 } }, // ur
        { { 0.0, 1.0 } }, // ul
      }
    };
    
    static std::array<std::array<unsigned, 6>, 12> const indices = {
      {
        // i_p1, i_p2, i_p3, i_t1, i_t2, i_t3
        { { 0, 1, 2, 0, 1, 2 } },
        { { 2, 3, 0, 2, 3, 0 } },
        { { 0, 3, 4, 1, 2, 0 } },
        { { 4, 3, 7, 0, 2, 3 } },
        { { 7, 6, 4, 2, 3, 1 } },
        { { 4, 6, 5, 1, 3, 0 } },
        { { 5, 6, 2, 1, 2, 3 } },
        { { 2, 1, 5, 2, 0, 1 } },
        { { 5, 1, 0, 1, 2, 3 } },
        { { 0, 4, 5, 3, 0, 1 } },
        { { 7, 3, 2, 3, 0, 1 } },
        { { 2, 6, 7, 1, 2, 3 } },
      }
    };

    unsigned idx_count(0);
    
    for (auto const& idx : indices) {
      glm::vec3 const& p1(points[idx[0]]);
      glm::vec3 const& p2(points[idx[1]]);
      glm::vec3 const& p3(points[idx[2]]);
      glm::vec3 const  n (glm::normalize(glm::cross(p1 - p2, p3 - p2)));
      glm::vec2 const  t1(tcoords[idx[3]][0], tcoords[idx[3]][1]);
      glm::vec2 const  t2(tcoords[idx[4]][0], tcoords[idx[4]][1]);
      glm::vec2 const  t3(tcoords[idx[5]][0], tcoords[idx[5]][1]);

      using node::geometry;
      
      attr_list.push_back(geometry::attribute(p1, n, t1));
      attr_list.push_back(geometry::attribute(p2, n, t2));
      attr_list.push_back(geometry::attribute(p3, n, t3));

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
      cube::cube()
        : node::geometry()
      {
        TRACE("hugh::scene::primitive::cube::cube");

        make_cube(attribute_list_, index_list_);
      
        compute_bounds();
        compute_tangents();
      }
    
      /* virtual */ void
      cube::accept(visitor::base& v)
      {
        TRACE("hugh::scene::primitive::cube::accept");

        v.visit(*this);
      }

    } // namespace primitive {
  
  } // namespace scene {

} // namespace hugh {
