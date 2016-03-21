// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/rotor.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_ROTOR_HPP)

#define HUGH_SCENE_NODE_ROTOR_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec3

// includes, project

#include <hugh/scene/node/dynamic.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT rotor : public dynamic {

      public:

        using subject_inherited = dynamic;

        field::value::single<glm::vec3> axis; //< rotation axis          [(0,1,0)]
        field::value::single<float>     rpm;  //< revolutions per minute [1.0]
      
        explicit rotor(float            /* rpm */  = 1.0,
                       glm::vec3 const& /* axis */ = glm::vec3(0,1,0));

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

#endif // #if !defined(HUGH_SCENE_NODE_ROTOR_HPP)
