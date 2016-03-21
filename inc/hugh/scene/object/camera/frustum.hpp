// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/frustum.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_CAMERA_FRUSTUM_HPP)

#define HUGH_SCENE_OBJECT_CAMERA_FRUSTUM_HPP

// includes, system

#include <iosfwd>      // std::ostream (fwd)
#include <glm/glm.hpp> // glm::vec3

// includes, project

#include <hugh/scene/export.h>

#ifdef far
#  pragma message("Note: undefining 'near'! (" __FILE__ ")")
#  undef far
#endif

#ifdef near
#  pragma message("Note: undefining 'far'! (" __FILE__ ")")
#  undef near
#endif

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace camera {
      
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT frustum {

        public:

          float left;   //< left boundary
          float right;  //< right boundary
          float bottom; //< lower boundary
          float top;    //< upper boundary
          float near;   //< near clipping plane (see glFrustum(3G))
          float far;    //< near clipping plane (see glFrustum(3G))

          explicit frustum(float /* left */   =  -1.00,
                           float /* right */  =   1.00,
                           float /* bottom */ =  -1.00,
                           float /* top */    =   1.00,
                           float /* near */   =   0.01,
                           float /* far */    = 100.00);

          bool contains(glm::vec3 const&) const;
        
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

        HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, frustum const&);
      
      } // namespace camera {

    } // namespace object {
      
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_CAMERA_FRUSTUM_HPP)
