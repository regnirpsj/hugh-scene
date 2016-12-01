// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_camera_frustum.cpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/camera/frustum.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_frustum)
{
  using namespace hugh::scene::object::camera;
  
  frustum const f;
  
  BOOST_CHECK(0.0 == (f.right + f.left));
  BOOST_CHECK(0.0 == (f.top   + f.bottom));
  BOOST_CHECK( f.contains(glm::vec3(0.0f, 0.0f, 2.0 * f.near)));
  BOOST_CHECK(!f.contains(glm::vec3(2.0f * f.left, 2.0 * f.bottom, 2.0 * f.near)));
  
  BOOST_TEST_MESSAGE(f);
}
