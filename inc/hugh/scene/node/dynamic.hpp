// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/dynamic.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_DYNAMIC_HPP)

#define HUGH_SCENE_NODE_DYNAMIC_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/scene/node/transform.hpp>
#include <hugh/support/chrono.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT dynamic : public transform {

      public:

        using subject_inherited = transform;
        using time_point        = support::clock::time_point;

        field::value::single<time_point> update; //< last update
      
        virtual ~dynamic() =0;
      
        virtual void accept(visitor::base&);

      protected:

        time_point last_update_;
      
        explicit dynamic();
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_DYNAMIC_HPP)
