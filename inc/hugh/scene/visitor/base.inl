// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/base.inl                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISITOR_BASE_INL)

#define HUGH_SCENE_VISITOR_BASE_INL

// includes, system

//#include <>

// includes, project

//#include <>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // functions, inlined (inline)

      template <typename T>
      inline void
      base::visit_base(T& o)
      {
        TRACE("hugh::scene::visitor::base::visit_base<" + support::demangle(typeid(T)) + ">");
      
        visit(static_cast<typename T::subject_inherited&>(o));
      }
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_SCENE_VISITOR_BASE_INL)
