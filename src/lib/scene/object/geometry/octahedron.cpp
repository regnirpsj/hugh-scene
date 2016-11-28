// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/octahedron.cpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/octahedron.hpp"

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

  using namespace hugh::scene::object;
  
  // variables, internal
  
  // functions, internal

  void
  make_octahedron(geometry::base::attribute_list_type& attr_list,
                  geometry::base::index_list_type&     index_list)
  {
    TRACE("hugh::scene::object::geometry::octahedron::<unnamed>::make_octahedron");

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
      glm::vec3 const& p0(points[idx[0]]);
      glm::vec3 const& p1(points[idx[1]]);
      glm::vec3 const& p2(points[idx[2]]);
      glm::vec3 const  n (glm::normalize(glm::cross(p1 - p0, p2 - p0)));
      
      attr_list.push_back(geometry::attribute(p0, n, glm::vec2(tcoords[0][0], tcoords[0][1])));
      attr_list.push_back(geometry::attribute(p1, n, glm::vec2(tcoords[1][0], tcoords[1][1])));
      attr_list.push_back(geometry::attribute(p2, n, glm::vec2(tcoords[2][0], tcoords[2][1])));

      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
      index_list.push_back(idx_count++);
    }
  }
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // variables, exported
    
        // functions, exported

        /* explicit */
        octahedron::octahedron()
          : base()
        {
          TRACE("hugh::scene::object::geometry::octahedron::octahedron");

          attribute_list_.clear();
          index_list_    .clear();

          make_octahedron(attribute_list_, index_list_);
      
          compute_bounds();
          compute_tangents();
        }

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
