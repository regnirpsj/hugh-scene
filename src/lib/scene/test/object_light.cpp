// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/objects_light.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/objects.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_base_rep)
{
  using namespace hugh::scene;
  
  object::light::base::rep const lr;
  
  BOOST_CHECK(false == lr.active);
  BOOST_TEST_MESSAGE("object_light_source_rep:" << lr << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_directional)
{
  using namespace hugh::scene;
  
  object::light::directional const l;
  
  BOOST_CHECK(false == *l.active);
  BOOST_TEST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_positional)
{
  using namespace hugh::scene;
  
  object::light::positional const l;
  
  BOOST_CHECK(false == *l.active);
  BOOST_TEST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_spot)
{
  using namespace hugh::scene;
  
  object::light::spot const l;
  
  BOOST_CHECK(false == *l.active);
  BOOST_TEST_MESSAGE(l << '\n');
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_area)
{
  using namespace hugh::scene;
  
  object::light::area l;

  l.exponent.set(1);
  l.cutoff.  set(12.5);
  
  l.size.    set(glm::uvec2(1, 2));
  l.samples. set(glm::uvec2(1, 4));

  l.size.    set(glm::uvec2(2, 1));
  l.samples. set(glm::uvec2(4, 1));

  l.size.    set(glm::uvec2(2, 2));
  l.samples. set(glm::uvec2(4, 4));

  l.size.    set(glm::uvec2( 6, 3));
  l.samples. set(glm::uvec2(10, 5));
  
  BOOST_CHECK(false == *l.active);
  BOOST_TEST_MESSAGE(l << '\n');
}
