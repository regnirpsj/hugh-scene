// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_camera_perspective.cpp                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <limits>         // std::numeric_limits<>

// includes, project

#include <hugh/scene/object/camera/perspective.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

  static float const eps(std::numeric_limits<float>::epsilon());
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_perspective)
{
  using namespace hugh::scene::object::camera;
  
  perspective const pc(glm::radians(45.0), viewport(1, 1, 2879, 1799),
                       glm::vec2(frustum().near, 10));
  
  BOOST_CHECK(eps > (glm::radians(45.0) - *pc.fovy));

  BOOST_TEST_MESSAGE(glm::io::precision(4) << pc);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_perspective_infty)
{
  using namespace hugh::scene::object::camera;

  perspective const pc(glm::radians(45.0), viewport(1, 1, 2879, 1799),
                       glm::vec2(frustum().near, std::numeric_limits<float>::infinity()));
  
  BOOST_CHECK(eps > (glm::radians(45.0) - *pc.fovy));

  BOOST_TEST_MESSAGE(glm::io::precision(4) << pc);
}
