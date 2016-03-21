// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/camera/base.cpp                                               */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/camera/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<

// includes, project

//#include <>

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

      namespace camera {
      
        // variables, exported
    
        // functions, exported

        /* virtual */
        base::~base()
        {
          TRACE("hugh::scene::object::camera::base::~base");
        }

        /* explicit */
        base::base(matrix_type const& a, viewport_type const& b, glm::vec2 const& c)
          : object::base(),
            projection  (*this, "projection",
                         std::bind(&base::cb_get_projection, this),
                         std::bind(&base::cb_set_projection, this, std::placeholders::_1)),
            frustum     (*this, "frustum",
                         std::bind(&base::cb_get_frustum, this),
                         std::bind(&base::cb_set_frustum, this, std::placeholders::_1)),
            viewport    (*this, "viewport",   b),
            projection_ (a),
            frustum_    (compute_frustum(b, c))
        {
          TRACE("hugh::scene::object::camera::base::base");
        }

        /* virtual */ void
        base::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::camera::base::do_changed");

          if      (&f == &projection) {}
          else if (&f == &frustum)    {}
          else if (&f == &viewport)   {}

          else {
            object::base::do_changed(f);
          }
        }

        base::frustum_type
        base::compute_frustum(viewport_type const& vp, glm::vec2 const& nf)
        {
          TRACE("hugh::scene::object::camera::base::compute_frustum");
        
          glm::vec2 const size (vp.width - vp.x, vp.height - vp.y);
          glm::vec2 const ratio(glm::vec2(size.x/size.x, size.y/size.x) * 2.f);
        
          return frustum_type(-ratio.x / 2.f, ratio.x / 2.f,
                              -ratio.y / 2.f, ratio.y / 2.f,
                              +nf.x,          nf.y);
        }
      
        base::matrix_type const&
        base::cb_get_projection() const
        {
          TRACE("hugh::scene::object::camera::base::cb_get_projection");

          return projection_;
        }
      
        base::matrix_type
        base::cb_set_projection(matrix_type const&)
        {
          TRACE("hugh::scene::object::camera::base::cb_set_projection");

          return cb_get_projection();
        }

        base::frustum_type const&
        base::cb_get_frustum() const
        {
          TRACE("hugh::scene::object::camera::base::cb_get_frustum");

          return frustum_;
        }

        base::frustum_type
        base::cb_set_frustum(frustum_type const&)
        {
          TRACE("hugh::scene::object::camera::base::cb_set_frustum");

          return cb_get_frustum();
        }
      
      } // namespace camera {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
