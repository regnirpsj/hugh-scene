// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016-2017 University of Hull                                                     */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/geometry/mesh.cpp                                             */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/geometry/mesh.hpp"

// includes, system

#include <glm/gtx/io.hpp>

// includes, project

#include <hugh/support/io.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace geometry {
        
        // variables, exported
    
        // functions, exported

        /* explicit */
        mesh::mesh(attribute_list_type const& a, index_list_type const& b)
          : base()
        {
          TRACE("hugh::scene::object::geometry::mesh::mesh");

          attribute_list_ = a;
          index_list_     = b;

          // remove_duplicates();
          compute_bounds   ();
          compute_tangents ();
        }        

        void
        mesh::remove_duplicates()
        {
          TRACE_ALWAYS("hugh::scene::object::geometry::mesh::remove_duplicates");

          attribute_list_type alist;

          for (unsigned i(0); i < index_list_.size(); ++i) {
            TRACE("hugh::scene::object::geometry::mesh::remove_duplicates: i=" +
                  std::to_string(i));
            
            unsigned const current_idx(index_list_[i]);
            
            std::cout << support::trace::prefix()
                      << i << ":" << current_idx
                      << std::endl;

            if (std::min(i, current_idx) >= alist.size()) {
              attribute_list_type::value_type const& current_attr(attribute_list_[current_idx]);
            
              for (unsigned j(i+1); j < index_list_.size(); ++j) {
                TRACE("hugh::scene::object::geometry::mesh::remove_duplicates: j=" +
                      std::to_string(j));
                
                unsigned& other_idx (index_list_[j]);

                if (other_idx >= alist.size()) {
                  attribute_list_type::value_type const& other_attr(attribute_list_[other_idx]);
                
                  if (current_attr == other_attr) {
#if 0
                    std::cout << support::trace::prefix()
                              << ": "
                              << other_idx << " -> " << current_idx
                              << std::endl;
#endif
                    
                    other_idx = current_idx;
                  }
                } else {
#if 0
                  std::cout << support::trace::prefix()
                            << ": "
                            << other_idx << " already fixed (loop j)"
                            << std::endl;
#endif
                }
              }
              
#if 1
              std::cout << support::trace::prefix()
                        << i << ": "
                        << current_idx << ": storing " << current_attr.position
                        << std::endl;
#endif

              alist.push_back(current_attr);

#if 0
              std::cout << support::trace::prefix()
                        << ": "
                        << alist.size() << " of " << attribute_list_.size()
                        << std::endl;
#endif
            } else {
#if 0
              std::cout << support::trace::prefix()
                        << ": "
                        << current_idx << " already fixed (loop i)"
                        << std::endl;
#endif
            }
            
            using support::ostream::operator<<;
            
            std::cout << support::trace::prefix()
                      << i << ':' << alist.size() << ": " << index_list_
                      << std::endl;
          }
          
          attribute_list_ = alist;
        }
        
      } // namespace geometry {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
