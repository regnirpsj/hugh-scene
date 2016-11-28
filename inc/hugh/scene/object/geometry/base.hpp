// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry/base.hpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_GEOMETRY_BASE_HPP)

#define HUGH_SCENE_OBJECT_GEOMETRY_BASE_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/field/adapter/multi.hpp>
#include <hugh/scene/object/base.hpp>
#include <hugh/scene/object/geometry/attribute.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT base : public object::base {

        public:

          using attribute_field_type = field::adapter::multi<attribute>;
          using attribute_list_type  = attribute_field_type::value_container_type;
          using index_field_type     = field::adapter::multi<unsigned>;
          using index_list_type      = index_field_type::value_container_type;
      
          attribute_field_type const attributes; //< attributes
          index_field_type const     indices;    //< indices

          virtual ~base() =0;

          void compute_bounds();
          void compute_tangents();
      
        protected:
      
          attribute_list_type attribute_list_;
          index_list_type     index_list_;
      
          explicit base();

        private:
      
          attribute_list_type const& cb_get_attributes() const;
          attribute_list_type        cb_set_attributes(attribute_list_type const&);
          bool                       cb_add_attribute (attribute const&);
          bool                       cb_sub_attribute (attribute const&);
      
          index_list_type const&     cb_get_indices() const;
          index_list_type            cb_set_indices(index_list_type const&);
          bool                       cb_add_index  (unsigned);
          bool                       cb_sub_index  (unsigned);
      
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)

        // functions, exported (extern)

      } // namesapce geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_GEOMETRY_BASE_HPP)
