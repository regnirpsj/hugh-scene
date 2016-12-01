// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_light_directional.cpp                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/light/directional.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_directional)
{
  using namespace hugh::scene;

  {
    object::light::directional const l;

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(false             == *l.active);
    BOOST_CHECK(glm::vec3(0,0,-1) == *l.direction);
    BOOST_CHECK(glm::vec3(0,0, 0) == *l.ambient);
    BOOST_CHECK(glm::vec3(1,1, 1) == *l.diffuse);
    BOOST_CHECK(glm::vec3(1,1, 1) == *l.specular);
    BOOST_CHECK(glm::vec3(1,0, 0) == *l.attenuation);

    BOOST_TEST_MESSAGE(l);
  }

  {
    object::light::directional l;

    BOOST_TEST_MESSAGE(l);
    
    l.active      = true;
    l.direction   = glm::vec3(0,0,1);
    l.ambient     = glm::vec3(1,1,1);
    l.diffuse     = glm::vec3(0,0,0);
    l.specular    = glm::vec3(0,0,0);
    l.attenuation = glm::vec3(1,1,1);

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(true             == *l.active);
    BOOST_CHECK(glm::vec3(0,0,1) == *l.direction);
    BOOST_CHECK(glm::vec3(1,1,1) == *l.ambient);
    BOOST_CHECK(glm::vec3(0,0,0) == *l.diffuse);
    BOOST_CHECK(glm::vec3(0,0,0) == *l.specular);
    BOOST_CHECK(glm::vec3(1,1,1) == *l.attenuation);

    BOOST_TEST_MESSAGE(l);
  }
}
