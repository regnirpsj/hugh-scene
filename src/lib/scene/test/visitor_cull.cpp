// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/test/visitor_cull.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <scene/nodes.hpp>
#include <scene/objects.hpp>
#include <scene/visitor/cull.hpp>

#include <visitor_shared.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_scene_visitor_cull)
{
  using namespace scene;
  
  node::group* g(test::make_scene());
  
  BOOST_CHECK(nullptr != g);
  
  node::camera                     c(new object::camera::perspective);
  visitor::cull::visible_list_type l;
  visitor::cull                    v(c, l);
  
  g->accept(v);

  BOOST_TEST_MESSAGE("visible geometry: " << l.size());
  
  delete g;
}
