// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  field/test/objects_camera.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <glm/gtx/utilities.hpp>
#include <scene/objects.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1900))
  float const angle45deg(float(45_deg));
#else
  float const angle45deg(float(45 _deg));
#endif
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_object_camera_frustum)
{
  using namespace scene::object::camera;
  
  frustum const f;
  
  BOOST_CHECK(0.0 == (f.right + f.left));
  BOOST_CHECK(0.0 == (f.top   + f.bottom));
  BOOST_CHECK( f.contains(glm::vec3(0.0f, 0.0f, 2.0 * f.near)));
  BOOST_CHECK(!f.contains(glm::vec3(2.0f * f.left, 2.0 * f.bottom, 2.0 * f.near)));
  BOOST_TEST_MESSAGE("scene::object::camera::frustum: " << f << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_viewport)
{
  using namespace scene::object::camera;
  
  viewport const v;
  
  BOOST_CHECK(v.width == v.height);
  BOOST_TEST_MESSAGE("scene::object::camera::viewport: " << v << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_orthographic)
{
  using namespace scene::object::camera;
  
  orthographic const oc(viewport(1, 1, 1599, 899));
  
  BOOST_CHECK(0.0 == (oc.frustum.get().right + oc.frustum.get().left));
  BOOST_CHECK(0.0 == (oc.frustum.get().top   + oc.frustum.get().bottom));
  BOOST_TEST_MESSAGE(oc << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_perspective)
{
  using namespace scene::object::camera;
  
  perspective const pc   (angle45deg, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, 10));
  
  BOOST_CHECK(angle45deg == pc.fovy.get());
  BOOST_TEST_MESSAGE(glm::io::precision(4) << pc << '\n');
}

BOOST_AUTO_TEST_CASE(test_scene_object_camera_perspective_infty)
{
  using namespace scene::object::camera;

  perspective const pc   (angle45deg, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, std::numeric_limits<float>::infinity()));
  
  BOOST_CHECK(angle45deg == pc.fovy.get());
  BOOST_TEST_MESSAGE(glm::io::precision(4) << pc << '\n');
}
