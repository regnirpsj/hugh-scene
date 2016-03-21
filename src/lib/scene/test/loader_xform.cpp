// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/loader_xform.cpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>

// includes, project

#include <loader/xform.hpp>
#include <scene/node/group.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::array<std::string const, 3> const filenames = {
    {
      "path/dummy.suffix.suffix.1E0,2.0,3.0,4.0.rot",
      "path/dummy.suffix.suffix.1.0,2.0,3.0.scale",
      "path/dummy.suffix.90.0,1,0,0.rot.-1.0,+2.0,3.0.trans",
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_loader_xform)
{
  for (auto f : filenames) {
    using namespace scene;
    
    boost::intrusive_ptr<node::group> g(file::xform::load(f));
    
    BOOST_CHECK(nullptr != g.get());
  }
}
