// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/visitor/test/visitor_print.cpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <iostream> // std::cout
#include <memory>   // std::unique_ptr<>

// includes, project

#include <scene/node/group.hpp>
#include <scene/visitor/print.hpp>

#include <visitor_shared.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class simple_bfs : public scene::visitor::bfs {

  public:
    
    virtual ~simple_bfs() { /* ... */ }

  private:

    virtual void visit(scene::visitor::subject&) { /* ... */ }
    
  };

  class simple_dfs : public scene::visitor::dfs {

  public:
    
    virtual ~simple_dfs() { /* ... */ }

  private:

    virtual void visit(scene::visitor::subject&) { /* ... */ }
    
  };
  
  // variables, internal
  
  // functions, internal
  
} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_simple_bfs)
{
  using namespace scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());

  simple_bfs v;
  
  g->accept(v);
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_simple_dfs)
{
  using namespace scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());

  simple_dfs v;

  g->accept(v);
  
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_graph_bfs)
{
  boost::test_tools::output_test_stream output;
  
  {
    // needs to be in a scope to ensure bfs' dtor is run to flush
    using namespace scene;
  
    std::unique_ptr<node::group> g(test::make_scene());
  
    BOOST_CHECK(nullptr != g.get());
  
    visitor::print pv(output, visitor::print::order::bfs);
    
    g->accept(pv);

#if 0
    visitor::print pv1(std::cout, visitor::print::order::bfs);
    g->accept(pv1);
#endif
  }

  BOOST_CHECK       (!output.is_empty(false));
  BOOST_TEST_MESSAGE(output.str());
}

BOOST_AUTO_TEST_CASE(test_scene_visitor_print_graph_dfs)
{
  boost::test_tools::output_test_stream output;
  
  using namespace scene;
  
  std::unique_ptr<node::group> g(test::make_scene());
  
  BOOST_CHECK(nullptr != g.get());
  
  visitor::print pv(output, visitor::print::order::dfs);
  g->accept(pv);
  
#if 0
  visitor::print pv1(std::cout, visitor::print::order::dfs);
  g->accept(pv1);
#endif
    
  BOOST_CHECK       (!output.is_empty(false));
  BOOST_TEST_MESSAGE(output.str());
}
