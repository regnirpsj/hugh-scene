// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  traversal/main.cpp                                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// includes, system

#include <cmath>    // std::pow<>
#include <cstdlib>  // EXIT_SUCCESS
#include <iostream> // std::cout, std::endl

// includes, project

#include <hugh/platform/posix.hpp>
#include <hugh/scene.hpp>
#include <hugh/support/chrono.hpp>
#include <hugh/support/chrono_io.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>
#if defined(HUGH_USE_TRACE) || defined(HUGH_ALL_TRACE)
#  include <typeinfo>
#  include <hugh/support/type_info.hpp>
#endif

#define HUGH_VERBOSE
//#undef HUGH_VERBOSE

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  namespace visitor {
    
    class count  : public hugh::scene::visitor::bfs,
                    public hugh::scene::visitor::dfs {

    public:
      
      enum class order { bfs, dfs, };

      explicit count(order a = order::dfs)
        : bfs    (),
          dfs    (),
          order_ (a),
          visits_(0)
      {
        TRACE("<unnamed>::visitor::count::count");
      }
      
      virtual ~count()
      {
        TRACE("<unnamed>::visitor::count::~count");

        switch (order_) {
        case order::bfs:
          {
            flush();
          }
          break;

        default:
          break;
        }
      }

      virtual void visit(hugh::scene::node::base&)
      {
        TRACE("<unnamed>::visitor::count::visit(hugh::scene::node::base)");

        ++visits_;
      }
      
      virtual void visit(hugh::scene::node::group& a)
      {
        TRACE("<unnamed>::visitor::count::visit(hugh::scene::node::group)");
        
        visit_helper(a);
      }

      virtual void print_on(std::ostream& os) const
      {
        TRACE_NEVER("<unnamed>::visitor::count::print_on");

        os << '[';

        switch (order_) {
        case order::bfs:
          os << "bfs";
          break;

        case order::dfs:
          os << "dfs";
          break;
        }

#if 0
        os << ','
           << std::setfill(' ')
           << std::setw(9)
           << std::fixed
           << std::right
           << visits_;
#endif
        
        os << ']';
      }

    private:
      
      order    order_;
      unsigned visits_;
      
      virtual void visit(hugh::scene::visitor::subject&)
      {
        TRACE("<unnamed>::visitor::count::visit(hugh::scene::visitor::subject)");
      }

      template <typename T> void visit_helper(T& t)
      {
        using namespace hugh;
        
        TRACE("<unnamed>::visitor::count::visit_helper(" + support::demangle(typeid(t)) + ")");

        visit(static_cast<scene::node::base&>(t));

        switch (order_) {
        case order::bfs:
          {
            bfs::visit(t);
          }
          break;

        case order::dfs:
          {
            dfs::visit(t);
          }
          break;
        }
      }

    };
    
  } // namespace visitor {
  
  using namespace hugh::platform;
  
  class app : public posix::application::base {

    using inherited  = posix::application::base;
    
  public:
    
    explicit app(application::command_line const& a)
      : inherited(a, !inherited::positionals)
    {
      TRACE("<unnamed>::app::app");
    }

    virtual signed run()
    {
      TRACE("<unnamed>::app::run");

      using namespace hugh::support;
      using namespace hugh::scene;
      
      timer tm;

      for (unsigned c(1); c <= 6; ++c) {
        unsigned const lvl(7 + (6 / c));
        
        for (unsigned l(0); l < lvl; ++l) {
#if defined(HUGH_VERBOSE)
          unsigned n(0);

          if (1 < c) {
            n = (std::pow(c, l+1) - 1) / (c-1);
          } else {
            n = l + 1;
          }

          std::cout << std::setfill(' ')
                    << std::setw(9)
                    << std::fixed
                    << std::right
                    << n << " nodes ("
                    << std::setw(2)
                    << l+1 << " level" << ((1 != l+1) ? "s" : " ") << ", "
                    << std::setw(2)
                    << c << " child" << ((1 != c) ? "ren" : "   ") << ") .. "
                    << std::flush;
#endif

          std::unique_ptr<node::group> root(new node::group);

          tm.reset();
        
          add(root.get(), l, c);
        
#if defined(HUGH_VERBOSE)
          std::cout << pretty_print(tm.lapse()) << std::flush;
#endif
          
          for (auto o : { visitor::count::order::dfs, visitor::count::order::bfs }) {
            static unsigned const iterations(500);

            tm.reset();
            
            for (unsigned loop(0); loop < iterations; ++loop) {
              visitor::count cv(o);
              
              root->accept(cv);
            }
            
#if defined(HUGH_VERBOSE)
            std::cout << " .. " << visitor::count(o) << ": "
                      << pretty_print(tm.lapse() / iterations)
                      << std::flush;
#endif
          }

#if defined(HUGH_VERBOSE)
          std::cout << std::endl;
#endif
        }

#if defined(HUGH_VERBOSE)
        std::cout << std::endl;
#endif        
      }
      
      return EXIT_SUCCESS;
    }

  private:

    void add(hugh::scene::node::group* g, unsigned l, unsigned c = 2)
    {
      TRACE("<unnamed>::app::add");

      if (0 < l) {
        for (unsigned i(0); i < c; ++i) {
          using namespace hugh::scene;
          
          node::group* child(new node::group);

          add(child, l-1, c);

          g->children += child;
        }
      }
    }
    
  };
  
  // variables, internal
  
  // functions, internal

} // namespace {

int
main(int argc, char const* argv[])
{
  TRACE("main");

  using namespace hugh::platform::application;
  
  return execute<app>(command_line(argc, argv), std::nothrow);
}
