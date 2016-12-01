// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_camera_orthographic.cpp                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/camera/orthographic.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_orthographic)
{
  using namespace hugh::scene::object::camera;
  
  orthographic const oc(viewport(1, 1, 1599, 899));
  
  BOOST_CHECK(0.0 == (oc.frustum.get().right + oc.frustum.get().left));
  BOOST_CHECK(0.0 == (oc.frustum.get().top   + oc.frustum.get().bottom));

  BOOST_TEST_MESSAGE(oc);
}
