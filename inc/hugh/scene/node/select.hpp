// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/select.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_SELECT_HPP)

#define HUGH_SCENE_NODE_SELECT_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/scene/node/group.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT select : public group {

      public:

        using subject_inherited = group;

        field::value::single<unsigned> index; //< index of selected child
      
        explicit select();

        virtual void accept(visitor::base&);

      protected:

        virtual void do_changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_SELECT_HPP)
