// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/loader_obj.cpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array> // std::array<>

// includes, project

#include <hugh/scene/node/group.hpp>
#include <hugh/scene/visitor/print.hpp>
#include <hugh/support/chrono.hpp>
#include <hugh/support/chrono_io.hpp>
#include <hugh/support/type_info.hpp>
#include <loader/obj.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  class simple_print : public hugh::scene::visitor::print {

  public:

    using order = hugh::scene::visitor::print::order;
    
    explicit simple_print(std::ostream& a, order b = order::dfs)
      : hugh::scene::visitor::print(a, b)
    {}

    virtual void visit(hugh::scene::node::base& a)
    {
      boost::io::ios_all_saver const ias(os_);

      os_ << std::string((2 * indent_), ' ')
          << hugh::support::demangle(typeid(a)) << ':'
          << a.name.get()
          << crlf_;
    }
    
  };

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
#include <boost/test/output_test_stream.hpp>

BOOST_AUTO_TEST_CASE(test_hugh_scene_loader_obj_cube)
{
  std::stringstream str;

  for (auto const& s : cube) {
    str << s << '\n';
  }
  
  BOOST_CHECK(nullptr != hugh::scene::file::obj::load(str));
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_loader_obj_squares)
{
  std::stringstream str;

  for (auto const& s : squares) {
    str << s << '\n';
  }
  
  BOOST_CHECK(nullptr != hugh::scene::file::obj::load(str));
}

BOOST_AUTO_TEST_CASE(test_hugh_scene_loader_obj_file)
{
  static std::array<std::string const, 19> const file_names = {
    {
      "/buddha/buddha.obj",
      "/conference/conference.obj",
      "/cornell-box/CornellBox-Empty-CO.obj",
      "/cornell-box/CornellBox-Empty-RG.obj",
      "/cornell-box/CornellBox-Empty-Squashed.obj",
      "/cornell-box/CornellBox-Empty-White.obj",
      "/cornell-box/CornellBox-Glossy.obj",
      "/cornell-box/CornellBox-Mirror.obj",
      "/cornell-box/CornellBox-Original.obj",
      "/cornell-box/CornellBox-Sphere.obj",
      "/cornell-box/CornellBox-Water.obj",
      "/cube/cube.obj",
      "/dabrovic-sponza/sponza.obj",
      "/dragon/dragon.obj",
      "/lost-empire/lost_empire.obj",
      "/mitsuba/mitsuba.obj",
      "/sibenik/sibenik.obj",
      "/sportscar/sportsCar.obj",
      "/teapot/teapot.obj",
    }
  };
  static std::string const prefix(std::string(CMAKE_INSTALL_PREFIX) + "/share/hugh/data/mcguire");
  
  using namespace hugh::scene;
  using namespace hugh::support;
  
  timer t;
  
  for (auto f : file_names) {
    auto const fname(prefix + f);

    t.reset();

    std::unique_ptr<node::group> g(file::obj::load(fname));

    BOOST_TEST_MESSAGE("load time was " << pretty_print(t.lapse()) << " for '" << fname << "'");
    BOOST_CHECK       (nullptr != g);

#if 0
    if (nullptr != g) {
      boost::test_tools::output_test_stream output;

      simple_print sp(output, simple_print::order::dfs);
      
      g->accept(sp);
        
      BOOST_CHECK       (!output.is_empty(false));
      BOOST_TEST_MESSAGE(output.str());
    }
#endif
  }
}
