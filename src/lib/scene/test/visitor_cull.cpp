// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/test/visitor_cull.cpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <hugh/scene/nodes.hpp>
#include <hugh/scene/objects.hpp>
#include <hugh/scene/visitor/cull.hpp>

#include <visitor_shared.hpp>

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
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_visitor_cull)
{
  using namespace hugh::scene;
  
  node::group* g(test::make_scene());
  
  BOOST_CHECK(nullptr != g);
  
  node::camera                     c(new object::camera::perspective);
  visitor::cull::visible_list_type l;
  visitor::cull                    v(c, l);
  
  g->accept(v);

  BOOST_TEST_MESSAGE("visible geometry: " << l.size());
  
  delete g;
}
