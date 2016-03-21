// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/visitor/print.hpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISITOR_PRINT_HPP)

#define HUGH_SCENE_VISITOR_PRINT_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/visitor/bfs.hpp>
#include <hugh/scene/visitor/dfs.hpp>

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT print : public bfs,
                                      public dfs {

      public:

        enum class order { bfs, dfs, };
    
        explicit print(std::ostream&, order = order::dfs);
        virtual ~print();

        virtual void visit(node::base&);
        virtual void visit(node::group&);
      
        virtual void print_on(std::ostream&) const;
      
      private:
    
        std::ostream& os_;
        order         order_;
        unsigned      indent_;
        char          crlf_;
      
        virtual void visit(subject&);
      
        template <typename T> void visit_helper(T&);
    
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_VISITOR_PRINT_HPP)
