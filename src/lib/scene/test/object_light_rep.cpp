// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/object_light_rep.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <sstream>        // std::ostringstream

// includes, project

#include <hugh/scene/object/light/base.hpp>

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

  BOOST_CHECK       (!ostr.str().empty());
  BOOST_TEST_MESSAGE(ostr.str());
}
