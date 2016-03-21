// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/base.cpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/light/base.hpp"

// includes, system

#include <glm/gtx/io.hpp> // glm::operator<<
#include <ostream>        // std::ostream

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

      namespace light {
      
        // variables, exported
    
        // functions, exported

        /* explicit */
        base::rep::rep(bool             a, // active
                       glm::vec4 const& b, // position
                       glm::vec3 const& c, // spot direction
                       glm::vec3 const& d, // ambient
                       glm::vec3 const& e, // diffuse
                       glm::vec3 const& f, // specular
                       glm::vec3 const& g, // attenuation
                       float            h, // spot exponent
                       float            i) // spot cutoff
          : position   (b),
            direction  (c),
            active     (a),
            ambient    (d),
            exponent   (h),
            diffuse    (e),
            cutoff     (i),
            specular   (f),
            pad0       (-1),
            attenuation(g),
            pad1       (-1)
        {   
          TRACE("hugh::scene::object::light::base::rep::rep");
        } 

        /* virtual */
        base::~base()
        {
          TRACE("hugh::scene::object::light::base::~base");
        }

        /* explicit */
        base::base(rep const& a)
          : object::base  (),
            representation(*this, "representation",
                           std::bind(&base::cb_get_rep_list, this),
                           std::bind(&base::cb_set_rep_list, this, std::placeholders::_1),
                           std::bind(&base::cb_add_rep,      this, std::placeholders::_1),
                           std::bind(&base::cb_sub_rep,      this, std::placeholders::_1)),
            active        (*this, "active",      a.active),
            ambient       (*this, "ambient",     a.ambient),
            diffuse       (*this, "diffuse",     a.diffuse),
            specular      (*this, "specular",    a.specular),
            attenuation   (*this, "attenuation", a.attenuation),
            rep_list_     (1, a)
        {   
          TRACE("hugh::scene::object::light::base::base");
        }
      
        /* virtual */ void
        base::do_changed(field::base& f)
        {
          TRACE("hugh::scene::object::light::base::do_changed");
        
          if      (&f == &active)      { rep_list_[0].active      = active.get();      }
          else if (&f == &ambient)     { rep_list_[0].ambient     = ambient.get();     }
          else if (&f == &diffuse)     { rep_list_[0].diffuse     = diffuse.get();     }
          else if (&f == &specular)    { rep_list_[0].specular    = specular.get();    }
          else if (&f == &attenuation) { rep_list_[0].attenuation = attenuation.get(); }
        
          else {
            object::base::do_changed(f);
          }
        }

        base::rep_list_type const&
        base::cb_get_rep_list() const
        {
          TRACE("hugh::scene::object::light::base::cb_get_rep_list");

          return rep_list_;
        }
      
        base::rep_list_type
        base::cb_set_rep_list(rep_list_type const&)
        {
          TRACE("hugh::scene::object::light::base::cb_set_rep_list");

          return rep_list_;
        }

        bool
        base::cb_add_rep(rep const&)
        {
          TRACE("hugh::scene::object::light::base::cb_add_rep");

          return false;
        }

        bool
        base::cb_sub_rep(rep const&)
        {
          TRACE("hugh::scene::object::light::base::cb_sub_rep");

          return false;
        }

        bool
        operator==(base::rep const& lhs, base::rep const& rhs)
        {
          TRACE("hugh::scene::object::light::operator==(base::rep, base::rep)");
      
          return ((&lhs == &rhs) ||
                  ((lhs.active      == rhs.active)      &&
                   (lhs.position    == rhs.position)    &&
                   (lhs.direction   == rhs.direction)   &&
                   (lhs.ambient     == rhs.ambient)     &&
                   (lhs.diffuse     == rhs.diffuse)     &&
                   (lhs.specular    == rhs.specular)    &&
                   (lhs.attenuation == rhs.attenuation) &&
                   (lhs.exponent    == rhs.exponent)    &&
                   (lhs.cutoff      == rhs.cutoff)));
        }        

        std::ostream&
        operator<<(std::ostream& os, base::rep const& a)
        {
          TRACE_NEVER("hugh::scene::object::operator<<(base::rep)");
      
          std::ostream::sentry const cerberus(os);

          if (cerberus) {
            os << '['
               << ((a.active) ? "" : "!") << "active,"
               << "pos:" << a.position    << ','
               << "dir:" << a.direction   << ','
               << "La:"  << a.ambient     << ','
               << "Ld:"  << a.diffuse     << ','
               << "Ls:"  << a.specular    << ','
               << "att:" << a.attenuation << ','
               << "exp:" << a.exponent    << ','
               << "cut:" << a.cutoff
               << ']';
          }

          return os;
        }

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
