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

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)

// includes, project

#include <hugh/field/adapter/multi.hpp>
#include <hugh/scene/node/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT geometry : public base {

      public:

        using subject_inherited = base;
      
        struct attribute {

        public:
        
          glm::vec3 position;
          glm::vec3 normal;
          glm::vec2 tcoord;
          glm::vec4 tangent;
          glm::vec4 color;

          explicit attribute(glm::vec3 const& /* position */ = glm::vec3(0.0),
                             glm::vec3 const& /* normal */   = glm::vec3(0.0),
                             glm::vec2 const& /* tcoord */   = glm::vec2(0.0),
                             glm::vec4 const& /* tangent */  = glm::vec4(0.0),
                             glm::vec4 const& /* color */    = glm::vec4(1.0));
        
        };

        using attribute_field_type = field::adapter::multi<attribute>;
        using attribute_list_type  = attribute_field_type::value_container_type;
        using index_field_type     = field::adapter::multi<unsigned>;
        using index_list_type      = index_field_type::value_container_type;
      
        attribute_field_type const attributes; //< attributes
        index_field_type const     indices;    //< indices

        virtual ~geometry() =0;

        virtual void accept(visitor::base&);

        void compute_bounds();
        void compute_tangents();
      
      protected:
      
        attribute_list_type attribute_list_;
        index_list_type     index_list_;
      
        explicit geometry();

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

      bool operator==(geometry::attribute const&, geometry::attribute const&);
    
      // functions, exported (extern)

      HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, geometry::attribute const&);
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#include <hugh/scene/node/geometry.inl>

#endif // #if !defined(HUGH_SCENE_NODE_GEOMETRY_HPP)
