// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/local_light.hpp                                                 */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_LOCAL_LIGHT_HPP)

#define HUGH_SCENE_NODE_LOCAL_LIGHT_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <hugh/scene/node/group.hpp>
#include <hugh/scene/object/light/directional.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT local_light : public group {

      public:

        using subject_inherited = group;
        using source_ptr_type   = boost::intrusive_ptr<object::light::base>;
      
        field::value::single<source_ptr_type> source; //< source
      
        explicit local_light();

        virtual void accept(visitor::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_LOCAL_LIGHT_HPP)
