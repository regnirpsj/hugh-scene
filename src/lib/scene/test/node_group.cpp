// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/node_group.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <scene/node/group.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_node_group_ctor)
{
  using namespace scene::node;
  
  group const g;
  
  BOOST_CHECK       (true == g.children.get().empty());
  BOOST_TEST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1) << g);
}

BOOST_AUTO_TEST_CASE(test_scene_node_group_add_child)
{
  using namespace scene::node;
  
  boost::intrusive_ptr<group> g(new group);

  BOOST_CHECK(true == g->children.get().empty());
  
  g->children += new group;
  g->children += new group;

  BOOST_CHECK(2 == g->children.get().size());

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  g->children = {};
#else
  g->children.set(group::children_field_type::value_container_type());
#endif
    
  BOOST_REQUIRE_THROW(g->children += g.get(), std::runtime_error);

  BOOST_CHECK(true == g->children.get().empty());
}

BOOST_AUTO_TEST_CASE(test_scene_node_group_set_children)
{
  using namespace scene::node;
  
  group  g0;
  group* g1(new group);
  group* g2(new group);

  BOOST_CHECK(true == g0.children.get().empty());

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  g0.children.set({ g1, g2 });
#else
  g0.children += g1;
  g0.children += g2;
#endif
  
  BOOST_CHECK       (2 == g0.children.get().size());
  BOOST_TEST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 1 + 1 + 1)
                     << g0 << '\n' << *g1 << '\n' << *g2);
  
  group* g3(new group);
  group* g4(new group);

#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1800))
  auto const old(g0.children.set({ g3, g4 }));
#else
  auto const old(g0.children.set(group::children_field_type::value_container_type()));
  g0.children += g1;
  g0.children += g2;
#endif
  
  BOOST_TEST_MESSAGE(glm::io::precision(1) << glm::io::width(1 + 0 + 1 + 1)
                     << g0 << '\n' << *g1 << '\n' << *g2 << '\n' << *g3 << '\n' << *g4);
  BOOST_CHECK       (2 == g0.children.get().size());
  BOOST_TEST_MESSAGE(glm::io::precision(1) << glm::io::width(0 + 0 + 1 + 1)
                     << g0 << '\n' << *g3 << '\n' << *g4);
}
