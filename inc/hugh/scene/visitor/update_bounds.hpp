// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/update_bounds.hpp                                            */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISITOR_UPDATE_BOUNDS_HPP)

#define HUGH_SCENE_VISITOR_UPDATE_BOUNDS_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/visitor/dfs.hpp>

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT update_bounds : public dfs {

      public:

        explicit update_bounds();
        virtual ~update_bounds();

        virtual void visit(node::geometry&);
        virtual void visit(node::group&);
        virtual void visit(node::transform&);

        virtual void print_on(std::ostream&) const;
      
      private:

        virtual void visit(subject&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)
    
    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_VISITOR_UPDATE_BOUNDS_HPP)
