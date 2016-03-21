// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/fill.inl                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_TEXTURE_FILL_INL)

#define HUGH_SCENE_OBJECT_TEXTURE_FILL_INL

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

    namespace object {

      namespace texture {

        // functions, inlined (inline)
      
        template <typename T, typename C>
        inline void
        fill(T& t, C const& c)
        {
          TRACE("hugh::scene::object::texture::fill<" + support::demangle(typeid(T)) + "," +
                support::demangle(typeid(C)) + ">");
          
          for (unsigned l(0); l < t.levels(); ++l){
            for (unsigned i(0); i < t.template size<C>(); ++i) {
              *(t[l].template data<C>() + i) = c;
            } 
          } 
        }
  
      } // namespace texture {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#if defined(HUGH_USE_TRACE)
#  undef HUGH_USE_TRACE
#endif

#endif // #if !defined(HUGH_SCENE_OBJECT_TEXTURE_FILL_INL)
