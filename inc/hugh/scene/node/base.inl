// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/base.inl                                                        */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_BASE_INL)

#define HUGH_SCENE_NODE_BASE_INL

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
      operator==(base::bounds const& lhs, base::bounds const& rhs)
      {
        TRACE("hugh::scene::node::operator==(base::bounds,base::bounds)");
      
        return ((&lhs == &rhs) ||
                ((lhs.min   == rhs.min) &&
                 (lhs.max   == rhs.max) &&
                 (lhs.valid == rhs.valid)));
      }

      inline bool
      operator!=(base::bounds const& lhs, base::bounds const& rhs)
      {
        TRACE("hugh::scene::node::operator!=(base::bounds,base::bounds)");
      
        return !(lhs == rhs);
      }

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_SCENE_NODE_BASE_INL)
