// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/base.hpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_TEXTURE_BASE_HPP)

#define HUGH_SCENE_OBJECT_TEXTURE_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::*

// includes, project

#include <hugh/scene/object/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
      
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT base : public object::base {

        public:

          static glm::uvec3 const default_size;  // (1,1,1)
          static glm::uvec4 const default_color; // (1,1,1,1)
      
          virtual ~base() =0;

          virtual bool empty() const =0;
      
        protected:
      
          explicit base();
      
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_TEXTURE_BASE_HPP)
