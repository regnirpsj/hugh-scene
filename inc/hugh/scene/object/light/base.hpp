// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/base.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_LIGHT_BASE_HPP)

#define HUGH_SCENE_OBJECT_LIGHT_BASE_HPP

// includes, system

#include <glm/glm.hpp> // glm::vec[3|4]
#include <iosfwd>      // std::ostream (fwd)
#include <vector>      // std::vector<>

// includes, project

#include <glm/gtx/utilities.hpp>
#include <hugh/field/adapter/multi.hpp>
#include <hugh/field/value/single.hpp>
#include <hugh/scene/object/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT base : public object::base {

        public:
      
          struct rep {

          public:
        
            glm::vec4 position;
            glm::vec3 direction;
            bool      active;
            glm::vec3 ambient;
            float     exponent;
            glm::vec3 diffuse;
            float     cutoff;
            glm::vec3 specular;
            float     pad0;
            glm::vec3 attenuation;
            float     pad1;
        
            explicit rep(bool              /* active */           = false,
                         glm::vec4 const&  /* position */         = glm::vec4(0.0, 0.0,  1.0, 0.0),
                         glm::vec3 const&  /* spot direction */   = glm::vec3(0.0, 0.0, -1.0),
                         glm::vec3 const&  /* ambient */          = glm::vec3(0.0, 0.0,  0.0),
                         glm::vec3 const&  /* diffuse */          = glm::vec3(1.0, 1.0,  1.0),
                         glm::vec3 const&  /* specular */         = glm::vec3(1.0, 1.0,  1.0),
                         glm::vec3 const&  /* attenuation */      = glm::vec3(1.0, 0.0,  0.0),
                         float             /* spot exponent */    = 0.0,
                         float             /* spot cutoff */      = glm::radians(180.0));
      
          };

          field::adapter::multi<rep> const representation; //< representation
          field::value::single<bool>       active;         //< active
          field::value::single<glm::vec3>  ambient;        //< ambient color
          field::value::single<glm::vec3>  diffuse;        //< diffuse color
          field::value::single<glm::vec3>  specular;       //< specular color
          field::value::single<glm::vec3>  attenuation;    //< attenuation (const, lin, quad)

          virtual ~base() =0;
      
        protected:

          using rep_list_type = std::vector<rep>;
        
          rep_list_type rep_list_;

          explicit base(rep const& /* rep */ = rep());
        
          virtual void do_changed(field::base&);

        private:

          rep_list_type const& cb_get_rep_list() const;
          rep_list_type        cb_set_rep_list(rep_list_type const&);
          bool                 cb_add_rep     (rep const&);
          bool                 cb_sub_rep     (rep const&);
        
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

        HUGH_SCENE_EXPORT bool operator==(base::rep const&, base::rep const&);
    
        HUGH_SCENE_EXPORT std::ostream& operator<<(std::ostream&, base::rep const&);

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_LIGHT_BASE_HPP)
