// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/material/base.hpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_MATERIAL_BASE_HPP)

#define HUGH_SCENE_OBJECT_MATERIAL_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace material {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT base : public object::base {

        public:

          virtual ~base() =0;

        protected:

          explicit base();
          
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace material {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_MATERIAL_BASE_HPP)
