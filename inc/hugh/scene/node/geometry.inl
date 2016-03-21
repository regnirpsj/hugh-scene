// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry.inl                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_GEOMETRY_INL)

#define HUGH_SCENE_NODE_GEOMETRY_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // functions, inlined (inline)

      inline bool
      operator==(geometry::attribute const& lhs, geometry::attribute const& rhs)
      {
        TRACE("hugh::scene::node::operator==(geometry::attribute,geometry::attribute)");
      
        return ((&lhs == &rhs) ||
                ((lhs.position == rhs.position) &&
                 (lhs.normal   == rhs.normal)   &&
                 (lhs.tcoord   == rhs.tcoord)   &&
                 (lhs.tangent  == rhs.tangent)  &&
                 (lhs.color    == rhs.color)));
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_SCENE_NODE_GEOMETRY_INL)
