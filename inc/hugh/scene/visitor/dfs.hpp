// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/vistor/dfs.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISTOR_DFS_HPP)

#define HUGH_SCENE_VISTOR_DFS_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/visitor/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT dfs : virtual public base {

      public:
      
        virtual ~dfs() =0;

        virtual void visit(node::group&);
      
        virtual void print_on(std::ostream&) const;      

      protected:

        explicit dfs();

      private:

        virtual void visit(subject&);
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_VISTOR_DFS_HPP)
