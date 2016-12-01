// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_light_spot.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <limits>         // std::numeric_limits<>

// includes, project

#include <hugh/scene/object/light/spot.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_spot)
{
  using namespace hugh::scene;

  static float const eps(std::numeric_limits<float>::epsilon());
  
  {
    object::light::spot const l;

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(false == *l.active);
    BOOST_CHECK(0.0   == *l.exponent);
    BOOST_CHECK(eps   >   (glm::radians(180.0) - *l.cutoff));

    BOOST_TEST_MESSAGE(l);
  }

  {
    object::light::spot l;

    BOOST_TEST_MESSAGE(l);
    
    l.active   = true;
    l.exponent = 64.0;
    l.cutoff   = glm::radians(45.0);

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(true  == *l.active);
    BOOST_CHECK(64.0  == *l.exponent);
    BOOST_CHECK(eps   >   (glm::radians(45.0) - *l.cutoff));

    BOOST_TEST_MESSAGE(l);
  }
}
