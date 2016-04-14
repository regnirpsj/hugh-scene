// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/viewport.hpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_CAMERA_VIEWPORT_HPP)

#define HUGH_SCENE_OBJECT_CAMERA_VIEWPORT_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec3
#include <iosfwd>      // std::ostream (fwd)

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

        struct HUGH_SCENE_EXPORT viewport {

        public:

          float x;      //< lower-left corner x-ccordinate
          float y;      //< lower-left corner y-ccordinate
          float width;  //< width
          float height; //< height
          float near;   //< window coordinates minimum depth (see glDepthRange(3G))
          float far;    //< window coordinates maximum depth (see glDepthRange(3G))

          explicit viewport(float /* x */      =   0.00,
                            float /* y */      =   0.00,
                            float /* width */  = 100.00,
                            float /* height */ = 100.00,
                            float /* near */   =   0.00,
                            float /* far */    =   1.00);

          bool contains(glm::vec3 const&) const;
          
        };
      
        // variables, exported (extern)

        // functions, inlined (inline)
        
        // functions, exported (extern)

        /**
         * \brief equality comparison operator for \c viewport
         */
        HUGH_SCENE_EXPORT bool operator==(viewport const&, viewport const&);

        /**
         * \brief \c std::ostream insertion operator for \c viewport
         */
        HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, viewport const&);
      
      } // namespace camera {

    } // namespace object {
      
  } // namespace scene {

} // namespace hugh {
    
#endif // #if !defined(HUGH_SCENE_OBJECT_CAMERA_VIEWPORT_HPP)
