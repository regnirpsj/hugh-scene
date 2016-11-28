// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_GEOMETRY_HPP)

#define HUGH_SCENE_NODE_GEOMETRY_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <hugh/scene/node/base.hpp>
#include <hugh/scene/object/geometry/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT geometry : public base {

      public:

        using subject_inherited = base;
        using object_ptr_type   = boost::intrusive_ptr<object::geometry::base>;
      
        field::value::single<object_ptr_type> object; //< object

        explicit geometry(object::geometry::base* /* object */ = nullptr);

        virtual void accept(visitor::base&);

        void compute_bounds();
        
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
      
      // functions, exported (extern)
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_GEOMETRY_HPP)
