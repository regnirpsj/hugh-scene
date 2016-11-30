// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/material_group.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_MATERIAL_GROUP_HPP)

#define HUGH_SCENE_NODE_MATERIAL_GROUP_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <hugh/scene/node/group.hpp>
#include <hugh/scene/object/materials.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT material_group : public group {

      public:

        using subject_inherited = group;
        using source_ptr_type   = boost::intrusive_ptr<object::material::base>;
      
        field::value::single<source_ptr_type> material; //< source
      
        explicit material_group();

        virtual void accept(visitor::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_MATERIAL_GROUP_HPP)
