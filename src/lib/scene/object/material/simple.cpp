// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/material/simple.cpp                                           */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "hugh/scene/object/material/simple.hpp"

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

      namespace material {
        
        // variables, exported

        /* static */ simple const simple::dflt_material;
    
        // functions, exported
    
        /* explicit */
        simple::rep::rep(glm::vec3 const& a, glm::vec3 const& b, glm::vec3 const& c,
                         glm::vec3 const& d, glm::vec3 const& e, float f, float g, float h, bool i,
                         bool j)
          : ambient(a), refraction(f), diffuse(b), shininess(g), emission(c), alpha(h), specular(d),
            front(i), transmission(e), back(j)
        {
          TRACE("hugh::scene::object::simple::rep::rep");
        }

        /* explicit */
        simple::simple(rep const& a)
          : base        (),
            ambient     (*this, "ambient",
                         std::bind(&simple::cb_get_ambient, this),
                         std::bind(&simple::cb_set_ambient, this, std::placeholders::_1)),
            diffuse     (*this, "diffuse",
                         std::bind(&simple::cb_get_diffuse, this),
                         std::bind(&simple::cb_set_diffuse, this, std::placeholders::_1)),
            emission    (*this, "emission",
                         std::bind(&simple::cb_get_emission, this),
                         std::bind(&simple::cb_set_emission, this, std::placeholders::_1)),
            specular    (*this, "specular",
                         std::bind(&simple::cb_get_specular, this),
                         std::bind(&simple::cb_set_specular, this, std::placeholders::_1)),
            transmission(*this, "transmission",
                         std::bind(&simple::cb_get_transmission, this),
                         std::bind(&simple::cb_set_transmission, this, std::placeholders::_1)),
            alpha       (*this, "alpha",
                         std::bind(&simple::cb_get_alpha, this),
                         std::bind(&simple::cb_set_alpha, this, std::placeholders::_1)),
            refraction  (*this, "refraction",
                         std::bind(&simple::cb_get_refraction, this),
                         std::bind(&simple::cb_set_refraction, this, std::placeholders::_1)),
            shininess   (*this, "shininess",
                         std::bind(&simple::cb_get_shininess, this),
                         std::bind(&simple::cb_set_shininess, this, std::placeholders::_1)),
            front       (*this, "front",
                         std::bind(&simple::cb_get_front, this),
                         std::bind(&simple::cb_set_front, this, std::placeholders::_1)),
            back        (*this, "back",
                         std::bind(&simple::cb_get_back, this),
                         std::bind(&simple::cb_set_back, this, std::placeholders::_1)),
            rep_        (a)
        {
          TRACE("hugh::scene::object::simple::material");
        }

        simple::operator simple::rep const& () const
        {
          TRACE("hugh::scene::object::simple::operator simple::rep const&");
      
          return rep_;
        }    

        glm::vec3 const&
        simple::cb_get_ambient() const
        {
          TRACE("hugh::scene::object::simple::cb_get_ambient");

          return rep_.ambient;
        }

        glm::vec3
        simple::cb_set_ambient(glm::vec3 const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_ambient");

          glm::vec3 const result(rep_.ambient);

          rep_.ambient = a;

          return result;
        }

        glm::vec3 const&
        simple::cb_get_diffuse() const
        {
          TRACE("hugh::scene::object::simple::cb_get_diffuse");

          return rep_.diffuse;
        }

        glm::vec3
        simple::cb_set_diffuse(glm::vec3 const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_diffuse");

          glm::vec3 const result(rep_.diffuse);

          rep_.diffuse = a;

          return result;
        }

        glm::vec3 const&
        simple::cb_get_emission() const
        {
          TRACE("hugh::scene::object::simple::cb_get_emission");

          return rep_.emission;
        }

        glm::vec3
        simple::cb_set_emission(glm::vec3 const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_emission");

          glm::vec3 const result(rep_.emission);

          rep_.emission = a;

          return result;
        }
    
        glm::vec3 const&
        simple::cb_get_specular() const
        {
          TRACE("hugh::scene::object::simple::cb_get_specular");

          return rep_.specular;
        }

        glm::vec3
        simple::cb_set_specular(glm::vec3 const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_specular");

          glm::vec3 const result(rep_.specular);

          rep_.specular = a;

          return result;
        }

        glm::vec3 const&
        simple::cb_get_transmission() const
        {
          TRACE("hugh::scene::object::simple::cb_get_transmission");

          return rep_.transmission;
        }

        glm::vec3
        simple::cb_set_transmission(glm::vec3 const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_transmission");

          glm::vec3 const result(rep_.transmission);

          rep_.transmission = a;

          return result;
        }

        float const&
        simple::cb_get_refraction() const
        {
          TRACE("hugh::scene::object::simple::cb_get_refraction");

          return rep_.refraction;
        }

        float
        simple::cb_set_refraction(float  const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_refraction");

          float const result(rep_.refraction);

          rep_.refraction = a;

          return result;
        }
    
        float const&
        simple::cb_get_shininess() const
        {
          TRACE("hugh::scene::object::simple::cb_get_shininess");

          return rep_.shininess;
        }

        float
        simple::cb_set_shininess(float const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_shininess");

          float const result(rep_.shininess);

          rep_.shininess = a;

          return result;
        }

        float const&
        simple::cb_get_alpha() const
        {
          TRACE("hugh::scene::object::simple::cb_get_alpha");

          return rep_.alpha;
        }

        float
        simple::cb_set_alpha(float const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_alpha");

          float const result(rep_.alpha);

          rep_.alpha = a;

          return result;
        }

        bool const&
        simple::cb_get_front() const
        {
          TRACE("hugh::scene::object::simple::cb_get_front");

          return rep_.front;
        }

        bool
        simple::cb_set_front(bool const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_front");

          bool const result(rep_.front);

          rep_.front = a;

          return result;
        }

        bool const&
        simple::cb_get_back() const
        {
          TRACE("hugh::scene::object::simple::cb_get_back");

          return rep_.back;
        }

        bool
        simple::cb_set_back(bool const& a)
        {
          TRACE("hugh::scene::object::simple::cb_set_back");

          bool const result(rep_.back);

          rep_.back = a;

          return result;
        }

        bool
        operator==(simple::rep const& lhs, simple::rep const& rhs)
        {
          TRACE("hugh::scene::object::operator==(simple::rep, simple::rep)");
      
          return ((&lhs == &rhs)                          ||
                  ((lhs.ambient      == rhs.ambient)      &&
                   (lhs.diffuse      == rhs.diffuse)      &&
                   (lhs.emission     == rhs.emission)     &&
                   (lhs.specular     == rhs.specular)     &&
                   (lhs.transmission == rhs.transmission) &&
                   (lhs.refraction   == rhs.refraction)   &&
                   (lhs.shininess    == rhs.shininess)    &&
                   (lhs.alpha        == rhs.alpha)        &&
                   (lhs.front        == rhs.front)        &&
                   (lhs.back         == rhs.back)));
        }
    
        std::ostream&
        operator<<(std::ostream& os, simple::rep const& a)
        {
          TRACE_NEVER("hugh::scene::object::operator<<(simple::rep)");

          std::ostream::sentry const cerberus(os);

          if (cerberus) {
            os << '['
               << "Ka:" << a.ambient        << ','
               << "Kd:" << a.diffuse        << ','
               << "Ke:" << a.emission       << ','
               << "Ks:" << a.specular       << ','
               << "Tf:" << a.transmission   << ','
               << "Ni:" << a.refraction     << ','
               << "Ns:" << a.shininess      << ','
               << "Tr:" << (1.0f - a.alpha) << ',';
        
            if      (a.front && a.back) { os << "front/back"; }
            else if (a.front)           { os << "front";      }
            else if (a.back)            { os << "back";       }
            else                        { os << "none";       }
        
            os << ']';
          }
      
          return os;
        }

      } // namespace material {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {
