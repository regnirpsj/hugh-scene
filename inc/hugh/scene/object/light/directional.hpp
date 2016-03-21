// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/directional.hpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP)

#define HUGH_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP

// includes, system

// #include <>

// includes, project

#include <hugh/scene/object/light/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT directional : virtual public base {

        public:      

          using rep = base::rep;
      
          static directional const dflt_light;

          field::value::single<glm::vec3> direction; //< light direction
      
          explicit directional();
      
        protected:
        
          virtual void do_changed(field::base&);
      
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_LIGHT_DIRECTIONAL_HPP)
