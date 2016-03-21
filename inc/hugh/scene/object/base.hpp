// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/base.hpp                                                      */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_BASE_HPP)

#define HUGH_SCENE_OBJECT_BASE_HPP

// includes, system

#include <string> // std::string

// includes, project

#include <hugh/field/container.hpp>
#include <hugh/field/value/single.hpp>
#include <hugh/support/refcounted.hpp>
#include <hugh/scene/export.h>

namespace hugh {
  
  namespace scene {

    namespace object {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT base : public field::container,
                                     public support::refcounted<base> {

      public:

        field::value::single<std::string> name; ///< name
      
        virtual ~base() =0;
      
        virtual void print_on(std::ostream&) const;
      
      protected:
      
        explicit base();
      
        virtual void do_changed(field::base&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace object {

  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_BASE_HPP)
