// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/orthographic.hpp                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP)

#define HUGH_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/camera/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace camera {
      
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT orthographic : public base {

        public:

          using subject_inherited = base;

          explicit orthographic(viewport_type const& /* viewport */ = viewport_type(),
                                glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                                frustum_type().far));
          virtual ~orthographic();

        protected:

          virtual void do_changed(field::base&);
        
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace camera {

    } // namespace object {
      
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_CAMERA_ORTHOGRAPHIC_HPP)
