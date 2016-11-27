// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/test/visitor_print.cpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <iostream> // std::cout
#include <memory>   // std::unique_ptr<>

// includes, project

#include <hugh/scene/node/group.hpp>
#include <hugh/scene/visitor/print.hpp>

#include <visitor_shared.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class simple_bfs : public hugh::scene::visitor::bfs {

  public:
    
    virtual ~simple_bfs() { /* ... */ }
    
  private:

    virtual void visit(hugh::scene::visitor::subject&) { /* ... */ }
    
  };

  class simple_dfs : public hugh::scene::visitor::dfs {

  public:
    
    virtual ~simple_dfs() { /* ... */ }

  private:

    virtual void visit(hugh::scene::visitor::subject&) { /* ... */ }
    
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_visitor_print_simple_bfs)
{
  using namespace hugh::scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());

  simple_bfs v;
  
  g->accept(v);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_visitor_print_simple_dfs)
{
  using namespace hugh::scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());

  simple_dfs v;

  g->accept(v);
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_visitor_print_graph_bfs)
{
  boost::test_tools::output_test_stream output;
  
  {
    // needs to be in a scope to ensure bfs' dtor is run to flush
    using namespace hugh::scene;
  
    std::unique_ptr<node::group> g(test::make_scene());
  
    BOOST_CHECK(nullptr != g.get());
  
    visitor::print pv(output, visitor::print::order::bfs);
    
    g->accept(pv);
  }

  BOOST_CHECK       (!output.is_empty(false));
  BOOST_TEST_MESSAGE(output.str());
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_visitor_print_graph_dfs)
{
  boost::test_tools::output_test_stream output;
  
  using namespace hugh::scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());
  
  visitor::print pv(output, visitor::print::order::dfs);
  g->accept(pv);
    
  BOOST_CHECK       (!output.is_empty(false));
  BOOST_TEST_MESSAGE(output.str());
}
