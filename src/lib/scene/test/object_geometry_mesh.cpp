// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_geometry_mesh.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/geometry/mesh.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_geometry_mesh_ctor)
{
  using namespace hugh::scene::object::geometry;

  mesh::attribute_list_type const a;
  mesh::index_list_type const     i;
  mesh const                      m(a, i);
  
  BOOST_CHECK       (m.bbox->valid);
  BOOST_CHECK       (m.attributes->empty());
  BOOST_CHECK       (m.indices->empty());  
  BOOST_TEST_MESSAGE(m);
}
