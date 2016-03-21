// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/loader/mtl.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_LOADER_MTL_HPP)

#define HUGH_SCENE_LOADER_MTL_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <iosfwd>                  // std::istream, std::ostream (fwd decl)
#include <string>                  // std::string
#include <vector>                  // std::vector<>

// includes, project

#include <hugh/scene/object/material.hpp>

namespace hugh {
  
  namespace scene {
  
    namespace file {

      namespace mtl {
      
        // types, exported (class, enum, struct, union, typedef)

        using list_type = std::vector<boost::intrusive_ptr<object::material>>;
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

        list_type load(std::istream&);
        list_type load(std::string const&);
        bool      save(std::ostream&,      list_type const&);
        bool      save(std::string const&, list_type const&);
      
      } // namespace mtl {
    
    } // namespace file {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_LOADER_MTL_HPP)
