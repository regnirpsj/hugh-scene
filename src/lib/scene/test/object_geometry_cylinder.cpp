// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_geometry_cylinder.cpp                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/geometry/cylinder.hpp>

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

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_geometry_cylinder_ctor,
                     *boost::unit_test::expected_failures(2))
{
  using namespace hugh::scene::object::geometry;
  
  cylinder const c;
  
  BOOST_CHECK       ( c.bbox->valid);
  BOOST_CHECK       (!c.attributes->empty()); // FAIL
  BOOST_CHECK       (!c.indices->empty());    // FAIL
  BOOST_CHECK       (cylinder::dflt_sides == *c.sides);
  BOOST_TEST_MESSAGE(c);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_geometry_cylinder_sides)
{
  using namespace hugh::scene::object::geometry;
  
  cylinder c;
  
  for (unsigned i(3); i <= 384; i *= 2) {
    c.sides = i;
  
    BOOST_CHECK       (c.bbox->valid);
    BOOST_CHECK       (i == *c.sides);
    BOOST_TEST_MESSAGE(std::right << std::setfill(' ')
                       << "sides:"  << std::setw(3) << *c.sides
                       << ", attr:" << std::setw(5) << c.attributes->size()
                       << ", idx:"  << std::setw(5) << c.indices->size());
  }
}
