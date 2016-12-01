// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_camera_viewport.cpp                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/camera/viewport.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_viewport)
{
  using namespace hugh::scene::object::camera;

  {
    viewport const v;
  
    BOOST_CHECK(viewport() == v);
  
    BOOST_TEST_MESSAGE(v);
  }

  {
    viewport const v(0, 0, 10,10, 0, 1);

    std::array<std::pair<glm::vec3 const, bool>, 11> const points = {
      {
        { glm::vec3( 5,  5,  0.5),  true },
        { glm::vec3( 0,  0,  0),    true },
        { glm::vec3( 0,  0,  1),    true },
        { glm::vec3( 0, 10,  0),    true },
        { glm::vec3( 0, 10,  1),    true },
        { glm::vec3(-1,  0,  0),   false },
        { glm::vec3(-1,  0,  1),   false },
        { glm::vec3( 0, 11,  0),   false },
        { glm::vec3( 0, 11,  1),   false },
        { glm::vec3( 5,  5, -1),   false },
        { glm::vec3( 5,  5,  2),   false },
      }
    };
    
    for (auto const& p : points) {
      BOOST_CHECK(p.second == v.contains(p.first));
    }
  }
}
