// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_light_area.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

#include <hugh/scene/object/light/area.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_object_light_area)
{
  using namespace hugh::scene;

  {
    object::light::area const l;

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::uvec2(0, 0) == *l.size);
    BOOST_CHECK(glm::uvec2(1, 1) == *l.samples);

    BOOST_TEST_MESSAGE(l);
  }

  {
    object::light::area l;

    BOOST_TEST_MESSAGE(l);
    
    l.size    = glm::uvec2(2, 2);
    l.samples = glm::uvec2(4, 4);

    BOOST_TEST_MESSAGE(l);
    
    BOOST_CHECK(false            == *l.active);
    BOOST_CHECK(glm::uvec2(2, 2) == *l.size);
    BOOST_CHECK(glm::uvec2(4, 4) == *l.samples);

    BOOST_TEST_MESSAGE(l);
  }
}
