// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/base.hpp                                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_BASE_HPP)

#define HUGH_SCENE_NODE_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::mat4, glm::vec3

// includes, project

#include <hugh/field/adapter/single.hpp>
#include <hugh/scene/object/base.hpp>
#include <hugh/scene/visitor/subject.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT base : public object::base,
                                     public visitor::subject {

      public:

        using subject_inherited = visitor::subject;

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
      
        using parent_field_type = field::adapter::single<base*>;
      
        parent_field_type const        parent;   //< parent node
        field::value::single<unsigned> travmask; //< traversal mask
        field::value::single<bounds>   bbox;     //< bounding box

        virtual ~base() noexcept(false) =0;
      
        virtual void accept(visitor::base&) =0;

        virtual glm::mat4 absolute_parent_xform() const;
        virtual glm::mat4 absolute_xform() const;
      
      protected:

        friend class group; // indirect access to parent_
      
        base* parent_;
      
        explicit base();
      
        virtual void do_changed(field::base&);

        virtual void invalidate_bounds();
      
      private:

        using parent_type = parent_field_type::value_type;
      
        parent_type const& cb_get_parent() const;
        parent_type        cb_set_parent(parent_type const&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)

      bool operator==(base::bounds const&, base::bounds const&);
      bool operator!=(base::bounds const&, base::bounds const&);
    
      // functions, exported (extern)

      HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, base::bounds const&);
    
    } // namespace node {

  } // namespace scene {

} // namespace hugh {

#include <hugh/scene/node/base.inl>

#endif // #if !defined(HUGH_SCENE_NODE_BASE_HPP)
