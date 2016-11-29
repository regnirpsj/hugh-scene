// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_geometry_sphere.cpp                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/geometry/sphere.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_geometry_sphere_ctor)
{
  using namespace hugh::scene::object::geometry;
  
  sphere const c(0);
  
  BOOST_CHECK       ( c.bbox->valid);
  BOOST_CHECK       (!c.attributes->empty());
  BOOST_CHECK       (!c.indices->empty());  
  BOOST_CHECK       (0 == *c.subdivision);
  BOOST_TEST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_geometry_sphere_subdivision)
{
  using namespace hugh::scene::object::geometry;
  
  sphere c(0);

  for (unsigned i(4); i < 9; ++i) {
    c.subdivision = i;
  
    BOOST_CHECK       (i == *c.subdivision);
    BOOST_TEST_MESSAGE(std::right << std::setfill(' ')
                       << "subdiv:"                 << *c.subdivision
                       << ", attr:" << std::setw(6) << c.attributes->size()
                       << ", idx:"  << std::setw(7) << c.indices->size());
  }
}
