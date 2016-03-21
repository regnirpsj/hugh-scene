// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/file.cpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/file.hpp"

// includes, system

#include <array>                      // std::array<>
#include <boost/algorithm/string.hpp> // boost::algorithm::to_lower
#include <boost/filesystem.hpp>       // boost::filesystem::*
#include <functional>                 // std::function<>
#include <map>                        // std::map<>
#include <tuple>                      // std::tuple<>

// includes, project

#include <hugh/scene/node/group.hpp>
#include <loader/obj.hpp>
#include <loader/xform.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  struct file_handler {

    using group              = hugh::scene::node::group;
    using load_function_type = std::function<group* (std::string const&)>;
    using save_function_type = std::function<bool   (std::string const&, group*)>;
    
    load_function_type load;
    save_function_type save;
    
  };
  
  using suffix_handler_map_type = std::map<std::string, file_handler>;

  class compare_suffixes {

  public:

    explicit compare_suffixes(std::string const& a)
      : s_(boost::algorithm::to_lower_copy(a))
    {
      TRACE_NEVER("hugh::scene::file::<unnamed>::compare_suffixes::compare_suffixes");
    }

    bool operator()(suffix_handler_map_type::value_type const& a) const
    {
      TRACE_NEVER("hugh::scene::file::<unnamed>::compare_suffixes::operator()");
      
      return s_ == boost::algorithm::to_lower_copy(a.first);
    }
    
  private:

    std::string const s_;
    
  };
  
  // functions, internal
  
  inline hugh::scene::node::group*
  obj_load(std::string const& a)
  {
    TRACE_NEVER("hugh::scene::file::<unnamed>::obj_load");

    return hugh::scene::file::obj::load(a);
  }
  
  inline bool
  obj_save(std::string const& a, hugh::scene::node::group* b)
  {
    TRACE_NEVER("hugh::scene::file::<unnamed>::obj_save");

    return hugh::scene::file::obj::save(a, b);
  }
  
  suffix_handler_map_type
  initialize_suffix_handler_map()
  {
    TRACE("hugh::scene::file::<unnamed>::initialize_suffix_handler_map");
    
    suffix_handler_map_type result;

    typedef file_handler::load_function_type load_fun;
    typedef file_handler::save_function_type save_fun;

    namespace hsfx = hugh::scene::file::xform;
    
    static std::array<std::tuple<std::string const, load_fun, save_fun>, 4> const suffixes = {
      {
        std::make_tuple(".obj",   &obj_load,   &obj_save),
        std::make_tuple(".rot",   &hsfx::load, &hsfx::save),
        std::make_tuple(".scale", &hsfx::load, &hsfx::save),
        std::make_tuple(".trans", &hsfx::load, &hsfx::save),
      }
    };
    
    for (auto const& s : suffixes) {
      file_handler fh;

      fh.load = std::get<1>(s);
      fh.save = std::get<2>(s);

      std::string const ext(boost::algorithm::to_lower_copy(std::get<0>(s)));
      
      result[ext] = fh;
    }
    
    return result;
  }

  // variables, internal
  
  suffix_handler_map_type const suffix_handler_map(initialize_suffix_handler_map());
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace file {
    
      // variables, exported
  
      // functions, exported

      /* static */ node::group*
      handler::load(std::string const& fname, type)
      {
        TRACE("hugh::scene::file::handler::load");

        namespace bfs = boost::filesystem;
      
        node::group*      result(nullptr);
        std::string const suffix(bfs::path(fname).extension().string());
        auto const        found (std::find_if(suffix_handler_map.begin(), suffix_handler_map.end(),
                                              compare_suffixes(suffix)));
      
        if (suffix_handler_map.end() != found) {
          result = found->second.load(fname);
        }
      
        return result;
      }
    
      /* static */ bool
      handler::save(std::string const& fname, node::group* root, type)
      {
        TRACE("hugh::scene::file::handler::save");

        namespace bfs = boost::filesystem;
      
        bool              result(false);
        std::string const suffix(bfs::path(fname).extension().string());
        auto const        found (std::find_if(suffix_handler_map.begin(), suffix_handler_map.end(),
                                              compare_suffixes(suffix)));
      
        if (suffix_handler_map.end() != found) {
          result = found->second.save(fname, root);
        }
      
        return result;
      }

    } // namespace file {
  
  } // namespace scene {

} // namespace hugh {
