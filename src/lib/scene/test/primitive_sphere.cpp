// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/primitive_sphere.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/primitive/sphere.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_primitive_sphere_ctor)
{
  using namespace hugh::scene::primitive;
  
  sphere const c(0);
  
  BOOST_CHECK       (true);
  BOOST_TEST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_primitive_sphere_subdiv)
{
  using namespace hugh::scene::primitive;
  
  sphere c(0);

  BOOST_TEST_MESSAGE(c);
  
  for (unsigned i(4); i < 9; ++i) {
    c.subdivision = i;
  
    BOOST_CHECK(i == *c.subdivision);
  }
}
