// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry/attribute.hpp                                          */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_HPP)

#define HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <hugh/scene/export.h>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT attribute {

        public:
        
          glm::vec3 position;
          glm::vec3 normal;
          glm::vec2 tcoord;
          glm::vec4 tangent;
          glm::vec4 color;

          explicit attribute(glm::vec3 const& /* position */ = glm::vec3(0.0),
                             glm::vec3 const& /* normal   */ = glm::vec3(0.0),
                             glm::vec2 const& /* tcoord   */ = glm::vec2(0.0),
                             glm::vec4 const& /* tangent  */ = glm::vec4(0.0),
                             glm::vec4 const& /* color    */ = glm::vec4(1.0));
        
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)

        bool operator==(attribute const&, attribute const&);
    
        // functions, exported (extern)

        HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, attribute const&);

      } // namesapce geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#include <hugh/scene/object/geometry/attribute.inl>

#endif // #if !defined(HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_HPP)
