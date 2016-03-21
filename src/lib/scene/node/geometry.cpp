// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/node/geometry.cpp                                                    */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/node/geometry.hpp"

// includes, system

#include <algorithm>      // std::remove<>
#include <glm/gtx/io.hpp> // glm::operator<<
#if defined(_OPENMP)
#  include <omp.h>        // omp_*
#endif
#include <ostream>        // std::ostream

// includes, project

#include <hugh/scene/visitor/base.hpp>

#define HUGH_USE_TRACE
#undef HUGH_USE_TRACE
#include <hugh/support/trace.hpp>

// internal unnamed namespace

namespace {
  
  // types, internal (class, enum, struct, union, typedef)

  // variables, internal
  
  // functions, internal

#if !defined(_OPENMP)
#  pragma clang diagnostic push
#  pragma clang diagnostic ignored "-Wunused-function"
  signed
  omp_get_thread_num()
  {
    return 0;
  }
  
  signed
  omp_get_num_threads()
  {
    return -1;
  }
#  pragma clang diagnostic pop
#endif
  
} // namespace {

namespace hugh {
  
  namespace scene {

    namespace node {
    
      // variables, exported
    
      // functions, exported

      /* explicit */
      geometry::attribute::attribute(glm::vec3 const& a, glm::vec3 const& b, glm::vec2 const& c,
                                     glm::vec4 const& d, glm::vec4 const& e)
        : position(a), normal(b), tcoord(c), tangent(d), color(e)
      {
        TRACE("hugh::scene::node::geometry::attribute::attribute");
      }
    
      /* virtual */
      geometry::~geometry()
      {
        TRACE("hugh::scene::node::geometry::~geometry");
      }

      /* virtual */ void
      geometry::accept(visitor::base& v)
      {
        TRACE("hugh::scene::node::geometry::accept");

        v.visit(*this);
      }
    
      void
      geometry::compute_bounds()
      {
        TRACE("hugh::scene::node::geometry::compute_bounds");

        bounds b(bounds::invalid);
      
        if (!attributes.get().empty()) {
          for (auto const& a : attributes.get()) {
            // glm::m[ax|in] return component-wise max/min, i.e. min([1,0,0], [0,1,-1]) -> [0,0,-1]
            b.min = glm::min(a.position, b.min);
            b.max = glm::max(a.position, b.max);
          }
        } else {
          b.min = b.max = glm::vec3(0.0);
        }

        b.valid = true;
      
        bbox = b;
      }

      /**
       * see [http://www.terathon.com/code/tangent.html]
       */
      void
      geometry::compute_tangents()
      {
        TRACE("hugh::scene::node::geometry::compute_tangents");
      
        std::vector<std::pair<glm::vec3, glm::vec3>> tarray(index_list_.size());

#if defined(_OPENMP)
#  pragma omp parallel for
#endif
        for (signed i = 0; i < signed(index_list_.size()); i += 3) {
          TRACE_NEVER("hugh::scene::node::geometry::compute_tangents:1:" +
                      std::to_string(i) + "/" +
                      std::to_string(index_list_.size()) + "(" +
                      std::to_string(omp_get_thread_num()) + "/" +
                      std::to_string(omp_get_num_threads()) + ")");
        
          unsigned const i1(index_list_[i+0]);
          unsigned const i2(index_list_[i+1]);
          unsigned const i3(index_list_[i+2]);
        
          glm::vec3 const& v1(attribute_list_[i1].position);
          glm::vec3 const& v2(attribute_list_[i2].position);
          glm::vec3 const& v3(attribute_list_[i3].position);

          glm::vec2 const& w1(attribute_list_[i1].tcoord);
          glm::vec2 const& w2(attribute_list_[i2].tcoord);
          glm::vec2 const& w3(attribute_list_[i3].tcoord);
        
          float const x1(v2.x - v1.x);
          float const x2(v3.x - v1.x);
          float const y1(v2.y - v1.y);
          float const y2(v3.y - v1.y);
          float const z1(v2.z - v1.z);
          float const z2(v3.z - v1.z);
        
          float const s1(w2.x - w1.x);
          float const s2(w3.x - w1.x);
          float const t1(w2.y - w1.y);
          float const t2(w3.y - w1.y);
        
          float const     r   (1.0f / (s1 * t2 - s2 * t1));
          glm::vec3 const sdir((t2 * x1 - t1 * x2) * r,
                               (t2 * y1 - t1 * y2) * r,
                               (t2 * z1 - t1 * z2) * r);
          glm::vec3 const tdir((s1 * x2 - s2 * x1) * r,
                               (s1 * y2 - s2 * y1) * r,
                               (s1 * z2 - s2 * z1) * r);
        
          for (signed k = i; k < i + 3; ++k) {
            tarray[k].first  += sdir;
            tarray[k].second += tdir;
          }
        }

#if defined(_OPENMP)
#  pragma omp parallel for
#endif
        for (signed i = 0; i < signed(index_list_.size()); ++i) {
          TRACE_NEVER("hugh::scene::node::geometry::compute_tangents:2:" +
                      std::to_string(i) + "/" +
                      std::to_string(index_list_.size()) + "(" +
                      std::to_string(omp_get_thread_num()) + "/" +
                      std::to_string(omp_get_num_threads()) + ")");
        
          auto const& idx(index_list_[i]);
          auto&       a  (attribute_list_[idx]);
          auto const& t  (tarray[idx]);
        
          a.tangent = glm::vec4(glm::normalize(t.first - a.normal * glm::dot(a.normal, t.first)),
                                ((0.0 > glm::dot(glm::cross(a.normal, t.first), t.second))
                                 ? -1.0f : 1.0f));
        }
      }
    
      /* explicit */
      geometry::geometry()
        : base           (),
          attributes     (*this, "attributes",
                          std::bind(&geometry::cb_get_attributes, this),
                          std::bind(&geometry::cb_set_attributes, this, std::placeholders::_1),
                          std::bind(&geometry::cb_add_attribute,  this, std::placeholders::_1),
                          std::bind(&geometry::cb_sub_attribute,  this, std::placeholders::_1)),
          indices        (*this, "indices",
                          std::bind(&geometry::cb_get_indices, this),
                          std::bind(&geometry::cb_set_indices, this, std::placeholders::_1),
                          std::bind(&geometry::cb_add_index,   this, std::placeholders::_1),
                          std::bind(&geometry::cb_sub_index,   this, std::placeholders::_1)),
          attribute_list_(),
          index_list_    ()
      {
        TRACE("hugh::scene::node::geometry::geometry");
      }

      geometry::attribute_list_type const&
      geometry::cb_get_attributes() const
      {
        TRACE("hugh::scene::node::geometry::cb_get_attributes");

        return attribute_list_;
      }
    
      geometry::attribute_list_type
      geometry::cb_set_attributes(attribute_list_type const& a)
      {
        TRACE("hugh::scene::node::geometry::cb_set_attributes");

        attribute_list_type const result(attribute_list_);
      
        attribute_list_ = a;

        return result;
      }

      bool
      geometry::cb_add_attribute(attribute const& a)
      {
        TRACE("hugh::scene::node::geometry::cb_add_attribute");

        attribute_list_.insert(attribute_list_.end(), a);

        return true;
      }
    
      bool
      geometry::cb_sub_attribute(attribute const& a)
      {
        TRACE("hugh::scene::node::geometry::cb_sub_attribute");

        attribute_list_.erase(std::remove(attribute_list_.begin(),
                                          attribute_list_.end(), a),
                              attribute_list_.end());

        return true;
      }
    
      geometry::index_list_type const&
      geometry::cb_get_indices() const
      {
        TRACE("hugh::scene::node::geometry::cb_get_indices");

        return index_list_;
      }
    
      geometry::index_list_type
      geometry::cb_set_indices(index_list_type const& a)
      {
        TRACE("hugh::scene::node::geometry::cb_set_indices");

        index_list_type const result(index_list_);
      
        index_list_ = a;

        return result;
      }

      bool
      geometry::cb_add_index(unsigned a)
      {
        TRACE("hugh::scene::node::geometry::cb_add_index");

        index_list_.insert(index_list_.end(), a);

        return true;
      }

      bool
      geometry::cb_sub_index(unsigned a)
      {
        TRACE("hugh::scene::node::geometry::cb_sub_index");

        index_list_.erase(std::remove(index_list_.begin(),
                                      index_list_.end(), a),
                          index_list_.end());

        return true;
      }
    
      std::ostream&
      operator<<(std::ostream& os, geometry::attribute const& a)
      {
        TRACE_NEVER("hugh::scene::node::operator<<(geometry::attribute)");
      
        std::ostream::sentry const cerberus(os);

        if (cerberus) {
          glm::io::format_saver const iofs(os);

          os << glm::io::precision(2)
             << glm::io::width(1 + 2 + 1 + os.precision())
             << '['
             << "v:"  << a.position << ','
             << "n:"  << a.normal   << ','
             << "tc:" << a.tcoord   << ','
             << "t:"  << a.tangent  << ','
             << "c:"  << a.color
             << ']';
        }

        return os;
      }
    
    } // namespace node {
  
  } // namespace scene {

} // namespace hugh {
