// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2014-2015 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  scene/test/obects_texture.cpp                                                   */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <array>         // std::array<>
#include <typeinfo>      // typeid usage
#include <unordered_map> // std::unordered_map<>

// includes, project

#include <scene/object/textures.hpp>
#include <support/type_info.hpp>

#define UKACHULLDCS_USE_TRACE
#undef UKACHULLDCS_USE_TRACE
#include <support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
#if defined(WIN32)
  std::string const prefix("c:/tools/gli/gli-git");
#else
  std::string const prefix("/home/jsd/Projects/others/gli-git");
#endif
  
  std::array<std::string const, 1> const file_list_d1 = {
    {
      // prefix + "/data/array_r8_unorm.dds",
      prefix + "/data/array_r8_uint.ktx",
    }
  };

  std::array<std::string const, 75> const file_list_d2 = {
    {
      prefix + "/data/kueken7_a8_unorm.dds",
      // prefix + "/data/kueken7_bgr8_srgb.dds",
      prefix + "/data/kueken7_bgr8_unorm.dds",
      prefix + "/data/kueken7_bgra8_srgb.dds",
      prefix + "/data/kueken7_bgra8_srgb.ktx",
      prefix + "/data/kueken7_bgra8_unorm.dds",
      prefix + "/data/kueken7_bgra8_unorm.ktx",
      prefix + "/data/kueken7_bgrx8_srgb.dds",
      prefix + "/data/kueken7_bgrx8_unorm.dds",
      prefix + "/data/kueken7_l8_unorm.dds",
      // prefix + "/data/kueken7_la8_unorm.dds",
      prefix + "/data/kueken7_r16_unorm.dds",
      prefix + "/data/kueken7_r5g6b5_unorm.dds",
      prefix + "/data/kueken7_r5g6b5_unorm.ktx",
      prefix + "/data/kueken7_r8_sint.dds",
      prefix + "/data/kueken7_r8_uint.dds",
      prefix + "/data/kueken7_r_ati1n_unorm.dds",
      prefix + "/data/kueken7_r_eac_snorm.ktx",
      prefix + "/data/kueken7_r_eac_unorm.ktx",
      prefix + "/data/kueken7_rg11b10_ufloat.dds",
      prefix + "/data/kueken7_rg11b10_ufloat.ktx",
      prefix + "/data/kueken7_rg_ati2n_unorm.dds",
      prefix + "/data/kueken7_rg_eac_snorm.ktx",
      prefix + "/data/kueken7_rg_eac_unorm.ktx",
      prefix + "/data/kueken7_rgb10a2_unorm.dds",
      prefix + "/data/kueken7_rgb10a2u.dds",
      // prefix + "/data/kueken7_rgb5a1_unorm.dds",
      prefix + "/data/kueken7_rgb5a1_unorm.ktx",
      // prefix + "/data/kueken7_rgb5a1_unorm_.dds",
      // prefix + "/data/kueken7_rgb8.jpg",
      prefix + "/data/kueken7_rgb8_srgb.ktx",
      prefix + "/data/kueken7_rgb8_unorm.ktx",
      prefix + "/data/kueken7_rgb9e5_ufloat.dds",
      prefix + "/data/kueken7_rgb9e5_ufloat.ktx",
      prefix + "/data/kueken7_rgb_atc_unorm.dds",
      prefix + "/data/kueken7_rgb_dxt1_srgb.dds",
      prefix + "/data/kueken7_rgb_dxt1_srgb.ktx",
      prefix + "/data/kueken7_rgb_dxt1_unorm.ktx",
      prefix + "/data/kueken7_rgb_etc1_unorm.dds",
      prefix + "/data/kueken7_rgb_etc1_unorm.ktx",
      prefix + "/data/kueken7_rgb_etc2_srgb.dds",
      prefix + "/data/kueken7_rgb_etc2_srgb.ktx",
      // prefix + "/data/kueken7_rgb_etc2_unorm.dds",
      prefix + "/data/kueken7_rgb_pvrtc_2bpp_srgb.ktx",
      prefix + "/data/kueken7_rgb_pvrtc_2bpp_unorm.dds",
      prefix + "/data/kueken7_rgb_pvrtc_4bpp_srgb.ktx",
      prefix + "/data/kueken7_rgb_pvrtc_4bpp_unorm.dds",
      prefix + "/data/kueken7_rgba16_sfloat.dds",
      prefix + "/data/kueken7_rgba16_sfloat.ktx",
      prefix + "/data/kueken7_rgba4_unorm.dds",
      prefix + "/data/kueken7_rgba4_unorm.ktx",
      prefix + "/data/kueken7_rgba8_snorm.dds",
      prefix + "/data/kueken7_rgba8_srgb.dds",
      prefix + "/data/kueken7_rgba8_srgb.ktx",
      prefix + "/data/kueken7_rgba8_unorm.dds",
      prefix + "/data/kueken7_rgba8_unorm.ktx",
      prefix + "/data/kueken7_rgba_astc12x12_srgb.ktx",
      prefix + "/data/kueken7_rgba_astc4x4_srgb.dds",
      prefix + "/data/kueken7_rgba_astc4x4_srgb.ktx",
      // prefix + "/data/kueken7_rgba_astc8x5_srgb.ktx",
      // prefix + "/data/kueken7_rgba_astc8x8_unorm.dds",
      prefix + "/data/kueken7_rgba_atc_explicit_unorm.dds",
      prefix + "/data/kueken7_rgba_atc_interpolate_unorm.dds",
      prefix + "/data/kueken7_rgba_dxt1_srgb.dds",
      prefix + "/data/kueken7_rgba_dxt1_unorm.dds",
      prefix + "/data/kueken7_rgba_dxt5_srgb.dds",
      prefix + "/data/kueken7_rgba_dxt5_srgb.ktx",
      prefix + "/data/kueken7_rgba_dxt5_unorm.dds",
      prefix + "/data/kueken7_rgba_dxt5_unorm.ktx",
      prefix + "/data/kueken7_rgba_dxt5_unorm1.dds",
      prefix + "/data/kueken7_rgba_dxt5_unorm2.dds",
      prefix + "/data/kueken7_rgba_etc2_a1_srgb.ktx",
      prefix + "/data/kueken7_rgba_etc2_srgb.ktx",
      prefix + "/data/kueken7_rgba_pvrtc2_2bpp_srgb.ktx",
      prefix + "/data/kueken7_rgba_pvrtc2_2bpp_unorm.ktx",
      prefix + "/data/kueken7_rgba_pvrtc2_4bpp_srgb.ktx",
      // prefix + "/data/kueken7_rgba_pvrtc2_4bpp_unorm.dds",
      prefix + "/data/kueken7_rgba_pvrtc2_4bpp_unorm.ktx",
      // prefix + "/data/kueken7_srgb8.jpg",
      // prefix + "/data/kueken7_srgb8.png",
      prefix + "/data/kueken8_bgr8_unorm.dds",
      prefix + "/data/kueken8_rgba8_srgb.dds",
      prefix + "/data/kueken8_rgba8_srgb.ktx",
      prefix + "/data/kueken8_rgba_dxt1_unorm.dds",
      // prefix + "/data/kueken8_srgb8.jpg",
      prefix + "/data/npot.ktx",
      prefix + "/data/test.dds",
    }
  };

  std::array<std::string const, 2> const file_list_d3 = {
    {
      prefix + "/data/cube_rgba8_unorm.dds",
      prefix + "/data/cube_rgba8_unorm.ktx",
    }
  };

  std::unordered_map<std::type_info const*, std::vector<std::string>> file_map = {
    {
      std::make_pair(&typeid(scene::object::texture::d1),
                     std::vector<std::string>(file_list_d1.begin(), file_list_d1.end())),
      std::make_pair(&typeid(scene::object::texture::d2),
                     std::vector<std::string>(file_list_d2.begin(), file_list_d2.end())),
      std::make_pair(&typeid(scene::object::texture::d3),
                     std::vector<std::string>(file_list_d3.begin(), file_list_d3.end())),
    }
  };
  
  // functions, internal

} // namespace {

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<scene::object::texture::d1,
                         scene::object::texture::d2,
                         scene::object::texture::d3> tex_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(test_scene_object_texture_ctor_fill, T, tex_types)
{
  T const t;

  BOOST_CHECK       (true);
  BOOST_TEST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(test_scene_object_texture_ctor_file, T, tex_types)
{
  for (auto const& f : file_map[&typeid(T)]) {
    T const t(f);

    BOOST_CHECK       (!t.empty());
    BOOST_TEST_MESSAGE(support::demangle(typeid(T)) << ':' << t);
  }
}
