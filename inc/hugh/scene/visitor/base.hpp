// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/base.hpp                                                     */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISITOR_BASE_HPP)

#define HUGH_SCENE_VISITOR_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/support/printable.hpp>
#include <hugh/scene/export.h>

namespace hugh {
  
  namespace scene {

    namespace node {

      class base;
      class camera;
      class dynamic;
      class geometry;
      class global_light;
      class group;
      class local_light;
      class material_group;
      class mesh;
      class rotor;
      class select;
      class transform;
      class translator;
    
    } // namespace node {

    namespace primitive {

      class cube;
      class cylinder;
      class icosahedron;
      class octahedron;
      class sphere;
      class tetrahedron;
    
    } // namespace primitive {
  
    namespace visitor {

      class subject;
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT base : public support::printable {

      public:

        virtual ~base() =0;

        virtual void visit(node::base&);
        virtual void visit(node::camera&);
        virtual void visit(node::dynamic&);
        virtual void visit(node::geometry&);
        virtual void visit(node::global_light&);
        virtual void visit(node::group&);
        virtual void visit(node::local_light&);
        virtual void visit(node::material_group&);
        virtual void visit(node::mesh&);
        virtual void visit(node::rotor&);
        virtual void visit(node::select&);
        virtual void visit(node::transform&);
        virtual void visit(node::translator&);
        virtual void visit(primitive::cube&);
        virtual void visit(primitive::cylinder&);
        virtual void visit(primitive::icosahedron&);
        virtual void visit(primitive::octahedron&);
        virtual void visit(primitive::sphere&);
        virtual void visit(primitive::tetrahedron&);
      
        virtual void print_on(std::ostream&) const;
      
      protected:

        explicit base();
      
        virtual void visit(subject&) =0;
      
        template <typename T> void visit_base(T&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace visitor {

  } // namespace scene {

} // namespace hugh {

#include <hugh/scene/visitor/base.inl>

#endif // #if !defined(HUGH_SCENE_VISITOR_BASE_HPP)
