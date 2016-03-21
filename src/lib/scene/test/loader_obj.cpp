// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/loader_obj.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>

// includes, project

#include <loader/obj.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::array<std::string const, 2> const cube = {
    {
      { "v 0.000000 2.000000 2.000000\n"
        "v 0.000000 0.000000 2.000000\n"
        "v 2.000000 0.000000 2.000000\n"
        "v 2.000000 2.000000 2.000000\n"
        "v 0.000000 2.000000 0.000000\n"
        "v 0.000000 0.000000 0.000000\n"
        "v 2.000000 0.000000 0.000000\n"
        "v 2.000000 2.000000 0.000000\n" },

      { "f 1 2 3 4\n"
        "f 8 7 6 5\n"
        "f 4 3 7 8\n"
        "f 5 1 4 8\n"
        "f 5 6 2 1\n"
        "f 2 6 7 3\n" },
    }
  };
  
  std::array<std::string const, 2> const squares = {
    {
      { "v 0.000000 2.000000 0.000000\n"
        "v 0.000000 0.000000 0.000000\n"
        "v 2.000000 0.000000 0.000000\n"
        "v 2.000000 2.000000 0.000000\n"
        "v 4.000000 0.000000 -1.255298\n"
        "v 4.000000 2.000000 -1.255298\n"
        "vn 0.000000 0.000000 1.000000\n"
        "vn 0.000000 0.000000 1.000000\n"
        "vn 0.276597 0.000000 0.960986\n"
        "vn 0.276597 0.000000 0.960986\n"
        "vn 0.531611 0.000000 0.846988\n"
        "vn 0.531611 0.000000 0.846988\n"
        "# 6 vertices\n"
        "# 6 normals\n" },
      
      {
        "g all\n"
        "s 1\n"
        "f 1//1 2//2 3//3 4//4\n"
        "f 4//4 3//3 5//5 6//6\n"
        "# 2 elements\n" },
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_loader_obj_cube)
{
  std::stringstream str;

  for (auto const& s : cube) {
    str << s << '\n';
  }
  
  BOOST_CHECK(nullptr != scene::file::obj::load(str));
}

BOOST_AUTO_TEST_CASE(test_scene_loader_obj_squares)
{
  std::stringstream str;

  for (auto const& s : squares) {
    str << s << '\n';
  }
  
  BOOST_CHECK(nullptr != scene::file::obj::load(str));
}
