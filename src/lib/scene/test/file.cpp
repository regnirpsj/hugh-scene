// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/file.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>
#include <tuple> // std::tuple<>

// includes, project

#include <scene/file.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  typedef std::tuple<std::string const,
                     std::string const,
                     scene::node::group*> file_load_save_tuple_type;

  
  // variables, internal

  std::array<file_load_save_tuple_type, 3> const file_names = {
    {
      std::make_tuple("test_load.dxf", "test_save.dxf", nullptr),
      std::make_tuple("test_load.obj", "test_save.obj", nullptr),
      std::make_tuple("test_load.pfb", "test_save.pfb", nullptr),
    }
  };
  
  // functions, internal

} // namespace {

// functions, exported

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_scene_file_load, file_names.size())

BOOST_AUTO_TEST_CASE(test_scene_file_load)
{
  using namespace scene::file;

  for (auto f : file_names) {
    std::string const& from(std::get<0>(f));

    BOOST_TEST_MESSAGE("loading from '" << from << "'");
    BOOST_CHECK       (nullptr != (std::get<2>(f) = handler::load(from)));
  }
}

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES(test_scene_file_save, file_names.size())

BOOST_AUTO_TEST_CASE(test_scene_file_save)
{
  using namespace scene::file;

  for (auto f : file_names) {
    std::string const& to(std::get<1>(f));

    BOOST_TEST_MESSAGE("saving to '" << to << "'");
    BOOST_CHECK       (handler::save(to, std::get<2>(f)));
  }
}
