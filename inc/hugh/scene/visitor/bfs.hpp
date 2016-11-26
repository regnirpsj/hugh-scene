// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/vistor/bfs.hpp                                                       */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_VISTOR_BFS_HPP)

#define HUGH_SCENE_VISTOR_BFS_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>
#include <queue>                   // std::queue<>

// includes, project

#include <hugh/scene/visitor/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace visitor {
    
      // types, exported (class, enum, struct, union, typedef)

      class HUGH_SCENE_EXPORT bfs : virtual public base {

      public:
      
        virtual ~bfs();
      
        virtual void visit(node::group&);
      
        virtual void print_on(std::ostream&) const;      

      protected:

        using node_queue_type = std::queue<boost::intrusive_ptr<node::base>>;

        node_queue_type node_queue_;
      
        explicit bfs();

        virtual void flush();      
      
      };
    
      // variables, exported (extern)

      // functions, inlined (inline)
  
      // functions, exported (extern)

    } // namespace visitor {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_VISTOR_BFS_HPP)
