// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/area.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/light/area.hpp"

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

  hugh::scene::object::light::base::rep const dflt_rep(false,
                                                       glm::vec4(0.0, 0.0,  1.0, 1.0),
                                                       glm::vec3(0.0, 0.0, -1.0),
                                                       glm::vec3(0.0, 0.0,  0.0),
                                                       glm::vec3(1.0, 1.0,  1.0),
                                                       glm::vec3(1.0, 1.0,  1.0),
                                                       glm::vec3(1.0, 0.0,  0.0),
                                                       0.0,
                                                       glm::radians(180.0));
  
  // functions, internal

} // namespace {

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // variables, exported

        /* static */ area const area::dflt_light;
    
        // functions, exported
    
        /* explicit */
        area::area()
          : base    (dflt_rep),
            spot    (),
            size    (*this, "size",    glm::uvec2(0, 0)),
            samples (*this, "samples", glm::uvec2(1, 1)),
            rep_    (dflt_rep),
            rebuild_(true)
        {
          TRACE("hugh::scene::object::light::area::area");

          rebuild();
        }
    
        /* virtual */ void
        area::do_evaluate()
        {
          TRACE("hugh::scene::object::light::area::do_evaluate");
        
          spot::evaluate();

          rebuild();
        }
      
        /* virtual */ void
        area::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::light::area::do_changed");
        
          if      (&f == &active)      { rep_.active         = active.get();      rebuild_ = true; }
          else if (&f == &ambient)     { rep_.ambient        = ambient.get();     rebuild_ = true; }
          else if (&f == &diffuse)     { rep_.diffuse        = diffuse.get();     rebuild_ = true; }
          else if (&f == &specular)    { rep_.specular       = specular.get();    rebuild_ = true; }
          else if (&f == &attenuation) { rep_.attenuation    = attenuation.get(); rebuild_ = true; }
          else if (&f == &direction)   { rep_.direction      = direction.get();   rebuild_ = true; }
          else if (&f == &position)    { rep_.position.xyz() = position.get();    rebuild_ = true; }
          else if (&f == &exponent)    { rep_.exponent       = exponent.get();    rebuild_ = true; }
          else if (&f == &cutoff)      { rep_.cutoff         = cutoff.get();      rebuild_ = true; }

          else if ((&f == &size) || (&f == &samples)) {
            rebuild_ = true;
          }
        
          else {
            spot::changed(f);
          }

          rebuild();
        }

        void
        area::rebuild()
        {
          TRACE("hugh::scene::object::light::area::rebuild");
        
          if (rebuild_) {
            if ((0 < size.get().x)    && (0 < size.get().y) &&
                (0 < samples.get().x) && (0 < samples.get().y)) {
              if ((2 > samples.get().x) && (2 > samples.get().y)) {
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
                rep_list_ = { rep_ };
#else
                rep_list_ = rep_list_type(1, rep_);
#endif
              } else {
                glm::vec2 const stride(glm::vec2(size.get()) / glm::vec2(samples.get()));
                glm::vec2 const start (-(glm::vec2(size.get()) / float(2.0)) +
                                       (stride / float(2.0)));
                glm::vec2 const stop  (  glm::vec2(size.get()) / float(2.0));
                glm::vec3 const scale (1.0 / (samples.get().x * samples.get().y));

                rep_list_.clear();
              
                for (float y(start.y); y < stop.y; y += stride.y) {
                  for (float x(start.x); x < stop.x; x += stride.x) {
                    rep const tmp(rep_.active,
                                  rep_.position + glm::vec4(x, y, 0, 0),
                                  rep_.direction,
                                  rep_.ambient  * scale,
                                  rep_.diffuse  * scale,
                                  rep_.specular * scale,
                                  rep_.attenuation,
                                  rep_.exponent / scale.x,
                                  rep_.cutoff);
                  
                    rep_list_.push_back(tmp);
                  }
                }
              }
            } else {
#if !defined(_MSC_VER) || (defined(_MSC_VER) && (_MSC_VER > 1700))
              rep_list_ = { rep_ };
#else
              rep_list_ = rep_list_type(1, rep_);
#endif
            }
          
            rebuild_ = false;
          }
        }
      
      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
