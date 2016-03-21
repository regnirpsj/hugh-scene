// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/subject.hpp                                                  */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISITOR_SUBJECT_HPP)

#define HUGH_SCENE_VISITOR_SUBJECT_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/export.h>

namespace hugh {
  
  namespace scene {

    namespace visitor {

      class base;
    
      // types, exported (class, enum, struct, union, typedef)

      /**
       * \brief a visitor-subject base class
       *
       * a visitor-subject base class to inherit from if handling of a type by visitors is required.
       * derived types need to implement \c accept, usually like this:
       *
       * <code>
       *  class subject_derived : public scene::visitor::subject {
       *
       *  public:
       *
       *    virtual void accept(visitor::base& v)
       *    {
       *      v.visit(*this);
       *    }
       *  };
       * </code>
       *
       * application usage is usually like this:
       *
       * <code>
       *  {
       *    some_visitor v;
       *
       *    subject_derived.accept(v);
       *  }
       * </code>
       */
      class HUGH_SCENE_EXPORT subject {

      public:

        virtual ~subject() =0;
      
        virtual void accept(visitor::base&) =0;
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_VISITOR_SUBJECT_HPP)
