// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/test/visitor_shared.cpp                                              */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

// include i/f header

#include "visitor_shared.hpp"

// includes, system

#include <array>                        // std::array<>
#include <glm/gtc/matrix_transform.hpp> // glm::lookAt
#include <glm/gtx/io.hpp>               // glm::io::*
#include <glm/gtx/transform.hpp>        // glm::rotate, glm::translate

// includes, project

#include <hugh/scene/nodes.hpp>
#include <hugh/scene/objects.hpp>
#include <hugh/scene/primitives.hpp>

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
    
    namespace test {
  
      // variables, exported
  
      // functions, exported

      node::group*
      make_scene()
      {
        TRACE("hugh::scene::test::make_scene");
        
        using namespace node;
        using namespace primitive;
    
        group* root(new group);
    
        {
          group* g(new group);

          {
            std::array<camera::base*, 2> const cameras = {
              {
                new camera(new object::camera::perspective),
                new camera(new object::camera::orthographic),
              }
            };

            std::array<transform*, 2> const xforms = {
              {
                new transform(glm::lookAt(glm::vec3(0,0,1), glm::vec3(0,0,0), glm::vec3(0,1, 0))),
                new transform(glm::lookAt(glm::vec3(0,1,0), glm::vec3(0,0,0), glm::vec3(0,0,-1))),
              }
            };
        
            for (unsigned i(0); i < cameras.size(); ++i) {
              xforms[i]->children += cameras[i];
          
              g->children += xforms[i];
            }
          }
  
          root->children += g;
        }
    
        {
          group* g(new group);

          {
            std::array<global_light*, 5> const lights = {
              {
                new global_light,
                new global_light,
                new global_light,
                new global_light,
                new global_light,
              }
            };
        
            for (auto const& l : lights) {
              g->children += l;
            }
          }

          root->children += g;
        }

        {
          group* g(new group);

          {
            std::array<transform*, 3> const transforms = {
              {
                new transform(glm::translate(glm::vec3(-10.0f, 0.0f, 0.0f))),
                new rotor    (2.0f, glm::vec3(1.0f, 1.0f, 1.0f)),
                new transform(glm::translate(glm::vec3(+10.0f, 0.0f, 0.0f))),
              }
            };

            for (auto const& t : transforms) {
              {
                std::array<material_group*, 3> const materials = {
                  {
                    new material_group,
                    new material_group,
                    new material_group,
                  }
                };
            
                for (auto const& m : materials) {
                  {
                    std::array<geometry*, 3> const primitives = {
                      {
                        new cube,
                        new sphere,
                        new tetrahedron,
                      }
                    };
                
                    for (auto const& p : primitives) {
                      m->children += p;
                    }
                  }
              
                  t->children += m;
                }
              }
          
              g->children += t;
            }
          }

          root->children += g;
        }
    
        return root;
      }
  
    } // namespace test {
    
  } // namespace scene {

} // namespace hugh {
