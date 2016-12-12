// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/group.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_NODE_GROUP_HPP)

#define HUGH_SCENE_NODE_GROUP_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
// #include <unordered_set>

// includes, project

#include <hugh/field/adapter/multi.hpp>
#include <hugh/scene/node/base.hpp>
#include <hugh/support/hasher.hpp>

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT group : public base {
      
      public:

        using subject_inherited   = base;
        using children_field_type =
          field::adapter::multi<boost::intrusive_ptr<base>,
                                std::unordered_multiset<boost::intrusive_ptr<base>>>;
      
        children_field_type children; //< children

        explicit group();
        virtual ~group();
      
        virtual void accept(visitor::base&);

      protected:
      
        using children_list_type = children_field_type::value_container_type;
        using children_type      = children_field_type::value_type;

        children_list_type children_list_;
      
      private:
      
        children_list_type const& cb_get_children() const;
        children_list_type        cb_set_children(children_list_type const&);
        bool                      cb_add_child   (children_type const&);
        bool                      cb_sub_child   (children_type const&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_NODE_GROUP_HPP)
