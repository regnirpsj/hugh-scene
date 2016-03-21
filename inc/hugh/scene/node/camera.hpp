// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/camera.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_CAMERA_HPP)

#define HUGH_SCENE_NODE_CAMERA_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <glm/glm.hpp>             // glm::mat4

// includes, project

#include <hugh/field/adapter/single.hpp>
#include <hugh/field/value/single.hpp>
#include <hugh/scene/object/camera/base.hpp>
#include <hugh/scene/node/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)
    
      class HUGH_SCENE_EXPORT camera : public base {
      
      public:
      
        using subject_inherited = base;
        using camera_ptr_type   = boost::intrusive_ptr<object::camera::base>;
      
        field::value::single<camera_ptr_type>   object; //< camera object
        field::adapter::single<glm::mat4> const view;   //< inverse(absolute_xform)

        explicit camera(object::camera::base* /* camera */);

        virtual void accept(visitor::base&);
      
      private:

        mutable glm::mat4 inverse_view_;
      
        glm::mat4 const& cb_get_view() const;
        glm::mat4        cb_set_view(glm::mat4 const&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_CAMERA_HPP)
