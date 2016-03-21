// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2015 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/loader_mtl.cpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>          // std::array<>
#include <glm/gtx/io.hpp> // glm::io::*

// includes, project

#include <loader/mtl.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal

  std::array<std::string const, 17> const materials = {
    {
      { "# Wavefront material file\n"
        "# Material examples from [http://www.fileformat.info/format/material/]\n" },
      
      { "newmtl 01_neon_green\n"
        "Kd 0.0000 1.0000 0.0000\n"
        "illum 0\n" },

      { "newmtl 02_flat_green\n"
        "Ka 0.0000 1.0000 0.0000\n"
        "Kd 0.0000 1.0000 0.0000\n"
        "illum 1\n" },

      { "newmtl 03_dissolved_green\n"
        "Ka 0.0000 1.0000 0.0000\n"
        "Kd 0.0000 1.0000 0.0000\n"
        "d 0.8000\n"
        "illum 1\n" },

      { "newmtl 04_shiny_green\n"
        "Ka 0.0000 1.0000 0.0000\n"
        "Kd 0.0000 1.0000 0.0000\n"
        "Ks 1.0000 1.0000 1.0000\n"
        "Ns 200.0000\n"
        "illum 1\n" },

      { "newmtl 05_green_mirror\n"
        "Ka 0.0000 1.0000 0.0000\n"
        "Kd 0.0000 1.0000 0.0000\n"
        "Ks 0.0000 1.0000 0.0000\n"
        "Ns 200.0000\n"
        "illum 3\n" },

      { "newmtl 06_fake_windshield\n"
        "Ka 0.0000 0.0000 0.0000\n"
        "Kd 0.0000 0.0000 0.0000\n"
        "Ks 0.9000 0.9000 0.9000\n"
        "d 0.1000\n"
        "Ns 200\n"
        "illum 4\n" },
      
      { "newmtl 07_fresnel_blue\n"
        "Ka 0.0000 0.0000 0.0000\n"
        "Kd 0.0000 0.0000 0.0000\n"
        "Ks 0.6180 0.8760 0.1430\n"
        "Ns 200\n"
        "illum 5\n" },

      { "newmtl 08_real_windshield\n"
        "Ka 0.0000 0.0000 0.0000\n"
        "Kd 0.0000 0.0000 0.0000\n"
        "Ks 0.0000 0.0000 0.0000\n"
        "Tf 1.0000 1.0000 1.0000\n"
        "Ns 200\n"
        "Ni 1.2000\n"
        "illum 6\n" },

      { "newmtl 09_fresnel_windshield\n"
        "Ka 0.0000 0.0000 1.0000\n"
        "Kd 0.0000 0.0000 1.0000\n"
        "Ks 0.6180 0.8760 0.1430\n"
        "Tf 1.0000 1.0000 1.0000\n"
        "Ns 200\n"
        "Ni 1.2000\n"
        "illum 7\n" },

      { "newmtl 10_tin\n"
        "Ka spectral tin.rfl\n"
        "Kd spectral tin.rfl\n"
        "Ks spectral tin.rfl\n"
        "Ns 200\n"
        "illum 3\n" },

      { "newmtl 11_pine_wood\n"
        "Ka spectral ident.rfl 1\n"
        "Kd spectral ident.rfl 1\n"
        "illum 1\n"
        "map_Ka pine.mpc\n"
        "map_Kd pine.mpc\n" },
      
      { "newmtl 12_bumpy_leather\n"
        "Ka spectral ident.rfl 1\n"
        "Kd spectral ident.rfl 1\n"
        "Ks spectral ident.rfl 1\n"
        "illum 2\n"
        "map_Ka brown.mpc\n"
        "map_Kd brown.mpc\n"
        "map_Ks brown.mpc\n"
        "bump -bm 2.000 leath.mpb\n" },

      { "newmtl 13_frosted_window\n"
        "Ka 0.2 0.2 0.2\n"
        "Kd 0.6 0.6 0.6\n"
        "Ks 0.1 0.1 0.1\n"
        "d 1\n"
        "Ns 200\n"
        "illum 2\n"
        "map_d -mm 0.200 0.800 window.mps\n" },

      { "newmtl 14_shifted_logo\n"
        "Ka spectral ident.rfl 1\n"
        "Kd spectral ident.rfl 1\n"
        "Ks spectral ident.rfl 1\n"
        "illum 2\n"
        "map_Ka -o 0.200 0.000 0.000 logo.mpc\n"
        "map_Kd -o 0.200 0.000 0.000 logo.mpc\n"
        "map_Ks -o 0.200 0.000 0.000 logo.mpc\n" },

      { "newmtl 15_scaled_logo\n"
        "Ka spectral ident.rfl 1\n"
        "Kd spectral ident.rfl 1\n"
        "Ks spectral ident.rfl 1\n"
        "illum 2\n"
        "map_Ka -s 1.200 1.200 0.000 logo.mpc\n"
        "map_Kd -s 1.200 1.200 0.000 logo.mpc\n"
        "map_Ks -s 1.200 1.200 0.000 logo.mpc\n" },

      { "newmtl 16_chrome_with_spherical_reflection_map\n"
        "Ka 0 0 0\n"
        "Kd 0 0 0\n"
        "Ks .7 .7 .7\n"
        "illum 1\n"
        "refl -type sphere chrome.rla\n" },
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_scene_loader_mtl_size)
{
  std::stringstream str;

  for (auto const& m : materials) {
    str << m << '\n';
  }

  // 'mtl::load' returns list of materials + dflt material
  BOOST_CHECK(materials.size() == scene::file::mtl::load(str).size());
}

BOOST_AUTO_TEST_CASE(test_scene_loader_mtl_properties)
{
  std::stringstream str;

  for (auto const& m : materials) {
    str << m << '\n';
  }

  using namespace scene::file;

  mtl::list_type const result(mtl::load(str));
  
  BOOST_CHECK("01_neon_green"          == result[1]->name.get());
  BOOST_CHECK(glm::vec3(0.0, 1.0, 0.0) == result[1]->diffuse.get());
}
