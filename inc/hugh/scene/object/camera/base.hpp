// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/base.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_CAMERA_BASE_HPP)

#define HUGH_SCENE_OBJECT_CAMERA_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec2

// includes, project

#include <hugh/field/adapter/single.hpp>
#include <hugh/field/value/single.hpp>
#include <hugh/scene/object/base.hpp>
#include <hugh/scene/object/camera/frustum.hpp>
#include <hugh/scene/object/camera/viewport.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace camera {
      
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT base : public object::base {

        public:

          using subject_inherited = object::base;
          using matrix_type       = glm::mat4;
          using frustum_type      = camera::frustum;
          using viewport_type     = camera::viewport;

          virtual ~base() =0;

          field::adapter::single<matrix_type> const  projection; //< projection xform
          field::adapter::single<frustum_type> const frustum;    //< frustum
          field::value::single<viewport_type>        viewport;   //< viewport

        protected:
        
          matrix_type  projection_;
          frustum_type frustum_;

          explicit base(matrix_type const&   /* projection */,
                        viewport_type const& /* viewport   */,
                        glm::vec2 const&     /* near/far   */);

          virtual void do_changed(field::base&);

          frustum_type compute_frustum(viewport_type const& /* viewport */,
                                       glm::vec2 const&     /* near/far */);
          
        private:
        
          matrix_type const&  cb_get_projection() const;
          matrix_type         cb_set_projection(matrix_type const&);
          frustum_type const& cb_get_frustum   () const;
          frustum_type        cb_set_frustum   (frustum_type const&);
        
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace camera {

    } // namespace object {
      
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_CAMERA_BASE_HPP)
