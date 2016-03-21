// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/translator.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_TRANSLATOR_HPP)

#define HUGH_SCENE_NODE_TRANSLATOR_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec3

// includes, project

#include <hugh/scene/node/dynamic.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT translator : public dynamic {

      public:

        using subject_inherited = dynamic;
      
        field::value::single<glm::vec3> direction; //< direction [(1,0,0)]
        field::value::single<float>     speed;     //< speed     [1.0]
      
        explicit translator(glm::vec3 const&   /* velocity */  = glm::vec3(1,0,0));
        explicit translator(float              /* speed */,
                            glm::vec3 const&   /* direction */ = glm::vec3(1,0,0));
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

#endif // #if !defined(HUGH_SCENE_NODE_TRANSLATOR_HPP)
