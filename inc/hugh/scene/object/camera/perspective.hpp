// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/perspective.hpp                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP)

#define HUGH_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/camera/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace camera {
      
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT perspective : public base {

        public:

          using subject_inherited = base;

          static float const default_fovy; //< default vertical vield-of-view (60 degrees)
        
          explicit perspective(float                /* fovy */     = default_fovy,
                               viewport_type const& /* viewport */ = viewport_type(),
                               glm::vec2 const&     /* near/far */ = glm::vec2(frustum_type().near,
                                                                               frustum_type().far));
          virtual ~perspective();

          field::value::single<float> fovy; ///< vertical field-of-view
        
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

#endif // #if !defined(HUGH_SCENE_OBJECT_CAMERA_PERSPECTIVE_HPP)
