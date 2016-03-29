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
#include <limits>         // std::numeric_limits<>
#include <sstream>        // std::ostringstream

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

  {
    object::light::base::rep const lr1;

    BOOST_CHECK(lr1 == lr);
  }
  
  std::ostringstream ostr;

  ostr << lr;

  BOOST_CHECK(!ostr.str().empty());
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_directional)
{
  using namespace hugh::scene;

  {
    object::light::directional const l;

    BOOST_CHECK(false             == *l.active);
    BOOST_CHECK(glm::vec3(0,0,-1) == *l.direction);
    BOOST_CHECK(glm::vec3(0,0, 0) == *l.ambient);
    BOOST_CHECK(glm::vec3(1,1, 1) == *l.diffuse);
    BOOST_CHECK(glm::vec3(1,1, 1) == *l.specular);
    BOOST_CHECK(glm::vec3(1,0, 0) == *l.attenuation);
  }

  {
    object::light::directional l;
    
    l.active      = true;
    l.direction   = glm::vec3(0,0,1);
    l.ambient     = glm::vec3(1,1,1);
    l.diffuse     = glm::vec3(0,0,0);
    l.specular    = glm::vec3(0,0,0);
    l.attenuation = glm::vec3(1,1,1);

    BOOST_CHECK(true             == *l.active);
    BOOST_CHECK(glm::vec3(0,0,1) == *l.direction);
    BOOST_CHECK(glm::vec3(1,1,1) == *l.ambient);
    BOOST_CHECK(glm::vec3(0,0,0) == *l.diffuse);
    BOOST_CHECK(glm::vec3(0,0,0) == *l.specular);
    BOOST_CHECK(glm::vec3(1,1,1) == *l.attenuation);
  }
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_positional)
{
  using namespace hugh::scene;
  
  {
    object::light::positional const l;

    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::vec3(0,0,1) == *l.position);
  }

  {
    object::light::positional l;
    
    l.active   = true;
    l.position = glm::vec3(0,0,-1);

    BOOST_CHECK(true              == *l.active);
    BOOST_CHECK(glm::vec3(0,0,-1) == *l.position);
  }
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_spot)
{
  using namespace hugh::scene;

  static float const eps(std::numeric_limits<float>::epsilon());
  
  {
    object::light::spot const l;
    
    BOOST_CHECK(false == *l.active);
    BOOST_CHECK(0.0   == *l.exponent);
    BOOST_CHECK(eps   >   (glm::radians(180.0) - *l.cutoff));
  }

  {
    object::light::spot l;
    
    l.active   = true;
    l.exponent = 64.0;
    l.cutoff   = glm::radians(45.0);
    
    BOOST_CHECK(true  == *l.active);
    BOOST_CHECK(64.0  == *l.exponent);
    BOOST_CHECK(eps   >   (glm::radians(45.0) == *l.cutoff));
  }
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_area)
{
  using namespace hugh::scene;

  {
    object::light::area const l;
    
    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::uvec2(0, 0) == *l.size);
    BOOST_CHECK(glm::uvec2(1, 1) == *l.samples);
  }

  {
    object::light::area l;
    
    l.size    = glm::uvec2(2, 2);
    l.samples = glm::uvec2(4, 4);
    
    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::uvec2(2, 2) == *l.size);
    BOOST_CHECK(glm::uvec2(4, 4) == *l.samples);
  }
}
