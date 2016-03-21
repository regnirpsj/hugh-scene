// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/visito_update_bounds.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <iostream> // std::cout

// includes, project

#include <scene/node/group.hpp>
#include <scene/visitor/print.hpp>
#include <scene/visitor/update_bounds.hpp>
#include <support/chrono.hpp>

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

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_scene_visitor_update_bounds)
{
  boost::test_tools::output_test_stream output;
  
  using namespace scene;
  
  node::group* g(test::make_scene());
  
  BOOST_CHECK(nullptr != g);
  
  if (true) {
    output << "\n----- Before BBox update " << std::string(100, '-') << '\n';
    
    visitor::print pv(output, visitor::print::order::dfs);
    
    g->accept(pv);

    BOOST_CHECK(!output.is_empty(true));
  }
  
  {
    output.flush();
    
    output << "\n----- Executing BBox update " << std::string(96, '-') << '\n';
    
    using namespace support;
    using namespace std::chrono;
    
    timer const t;
    
    clock::duration const t0(t.lapse());
    
    visitor::update_bounds uv;
    
    clock::duration const t1(t.lapse());
    
    g->accept(uv);
    
    clock::duration const t2(t.lapse());

    BOOST_CHECK(true == g->bbox.get().valid);
    
    output << "setup  : " << duration_cast<microseconds>(t1 - t0).count() << "us\n"
           << "update : " << duration_cast<microseconds>(t2 - t1).count() << "us\n"
           << "overall: " << duration_cast<microseconds>(t2 - t0).count() << "us"
           << std::endl;

    BOOST_CHECK(!output.is_empty(true));
  }

  if (true) {    
    output << "\n----- After BBox update " << std::string(100, '-') << '\n';
    
    visitor::print pv(std::cout, visitor::print::order::dfs);
    
    g->accept(pv);

    BOOST_CHECK(!output.is_empty(true));
  }
  
  delete g;
}
