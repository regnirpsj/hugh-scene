// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/material/textured.hpp                                         */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_MATERIAL_TEXTURED_HPP)

#define HUGH_SCENE_OBJECT_MATERIAL_TEXTURED_HPP

// includes, system

#include <boost/intrusive_ptr.hpp> // boost::intrusive_ptr<>

// includes, project

#include <hugh/field/value/single.hpp>
#include <hugh/scene/object/material/simple.hpp>
#include <hugh/scene/object/texture/d2.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace material {
        
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT textured : public simple {

        public:
          
          using texture_type       = object::texture::d2;
          using texture_field_type = field::value::single<boost::intrusive_ptr<texture_type>>;
          
          static textured const   dflt_material;
          static glm::uvec2 const dflt_tex_size;  // (1,1)
          static glm::uvec4 const dflt_tex_black;
          static glm::uvec4 const dflt_tex_white;
          
          texture_field_type ambient;  //< ambient texture
          texture_field_type diffuse;  //< diffuse texture
          texture_field_type emission; //< emission texture
          texture_field_type specular; //< specular texture
          
          textured(simple::rep const& /* simple rep */ = simple::rep(),
                   texture_type*      /* ambient    */ = new texture_type(dflt_tex_size,
                                                                          dflt_tex_white),
                   texture_type*      /* diffuse    */ = new texture_type(dflt_tex_size,
                                                                          dflt_tex_white),
                   texture_type*      /* emission   */ = new texture_type(dflt_tex_size,
                                                                          dflt_tex_white),
                   texture_type*      /* specular   */ = new texture_type(dflt_tex_size,
                                                                          dflt_tex_white));
          
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace material {
      
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_MATERIAL_TEXTURED_HPP)
