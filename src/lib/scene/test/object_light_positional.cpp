// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_light_positional.cpp                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/light/positional.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_positional)
{
  using namespace hugh::scene;
  
  {
    object::light::positional const l;

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::vec3(0,0,1) == *l.position);

    BOOST_TEST_MESSAGE(l);
  }

  {
    object::light::positional l;

    BOOST_TEST_MESSAGE(l);
    
    l.active   = true;
    l.position = glm::vec3(0,0,-1);

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(true              == *l.active);
    BOOST_CHECK(glm::vec3(0,0,-1) == *l.position);

    BOOST_TEST_MESSAGE(l);
  }
}
