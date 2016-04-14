// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/objects_camera.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::operator<<
#include <sstream>        // std::ostringstream

// includes, project

#include <glm/gtx/utilities.hpp>
#include <hugh/scene/objects.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_frustum)
{
  using namespace hugh::scene::object::camera;
  
  frustum const f;
  
  BOOST_CHECK(0.0 == (f.right + f.left));
  BOOST_CHECK(0.0 == (f.top   + f.bottom));
  BOOST_CHECK( f.contains(glm::vec3(0.0f, 0.0f, 2.0 * f.near)));
  BOOST_CHECK(!f.contains(glm::vec3(2.0f * f.left, 2.0 * f.bottom, 2.0 * f.near)));

  std::ostringstream ostr;

  ostr << f;
  
  BOOST_CHECK(!ostr.str().empty());
  
  BOOST_TEST_MESSAGE("scene::object::camera::frustum: " << ostr.str() << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_viewport)
{
  using namespace hugh::scene::object::camera;

  {
    viewport const v;
  
    BOOST_CHECK(viewport() == v);
  
    std::ostringstream ostr;

    ostr << v;
  
    BOOST_CHECK(!ostr.str().empty());
  
    BOOST_TEST_MESSAGE("scene::object::camera::viewport: " << ostr.str() << '\n');
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

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_orthographic)
{
  using namespace hugh::scene::object::camera;
  
  orthographic const oc(viewport(1, 1, 1599, 899));
  
  BOOST_CHECK(0.0 == (oc.frustum.get().right + oc.frustum.get().left));
  BOOST_CHECK(0.0 == (oc.frustum.get().top   + oc.frustum.get().bottom));

  std::ostringstream ostr;

  ostr << oc;
  
  BOOST_CHECK(!ostr.str().empty());
  
  BOOST_TEST_MESSAGE(ostr.str() << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_perspective)
{
  using namespace hugh::scene::object::camera;
  
  perspective const pc   (angle45deg, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, 10));
  
  BOOST_CHECK(angle45deg == pc.fovy.get());

  std::ostringstream ostr;

  ostr << pc;
  
  BOOST_CHECK(!ostr.str().empty());
  
  BOOST_TEST_MESSAGE(glm::io::precision(4) << ostr.str() << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_camera_perspective_infty)
{
  using namespace hugh::scene::object::camera;

  perspective const pc   (angle45deg, viewport(1, 1, 2879, 1799),
                          glm::vec2(frustum().near, std::numeric_limits<float>::infinity()));
  
  BOOST_CHECK(angle45deg == pc.fovy.get());

  std::ostringstream ostr;

  ostr << pc;
  
  BOOST_CHECK(!ostr.str().empty());
  
  BOOST_TEST_MESSAGE(glm::io::precision(4) << ostr.str() << '\n');
}
