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

#include <glm/glm.hpp> // glm::vec3
#include <string>      // std::string

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

        struct bounds {

        public:

          static bounds const invalid; // { [+inf, +inf, +inf], [-inf, -inf, -inf], false, }

          glm::vec3 min;
          glm::vec3 max;
          bool      valid;

          explicit bounds(glm::vec3 const& /* min */   = invalid.min,
                          glm::vec3 const& /* max */   = invalid.max,
                          bool             /* valid */ = invalid.valid);
        
        };
        
        field::value::single<std::string> name; //< name
        field::value::single<bounds>      bbox; //< bounding box
      
        virtual ~base() =0;
      
        virtual void print_on(std::ostream&) const;
      
      protected:
      
        explicit base();
      
        virtual void do_changed(field::base&);

        virtual void invalidate_bounds();

      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      bool operator==(base::bounds const&, base::bounds const&);
      bool operator!=(base::bounds const&, base::bounds const&);
      
      // functions, exported (extern)

      HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, base::bounds const&);
      
    } // namespace object {

  } // namespace scene {

} // namespace hugh {

#include <hugh/scene/object/base.inl>

#endif // #if !defined(HUGH_SCENE_OBJECT_BASE_HPP)
