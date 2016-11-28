// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/attribute.inl                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_INL)

#define HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // functions, inlined (inline)

        inline bool
        operator==(attribute const& lhs, attribute const& rhs)
        {
          TRACE("hugh::scene::object::geometry::operator==(attribute,attribute)");
      
          return ((&lhs == &rhs) ||
                  ((lhs.position == rhs.position) &&
                   (lhs.normal   == rhs.normal)   &&
                   (lhs.tcoord   == rhs.tcoord)   &&
                   (lhs.tangent  == rhs.tangent)  &&
                   (lhs.color    == rhs.color)));
        }

      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_SCENE_OBJECT_GEOMETRY_ATTRIBUTE_INL)
