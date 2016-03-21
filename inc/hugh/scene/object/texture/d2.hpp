// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/d2.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_TEXTURE_D2_HPP)

#define HUGH_SCENE_OBJECT_TEXTURE_D2_HPP

// includes, system

#include <gli/gli.hpp> // gli::texture?d
#include <string>      // std::string

// includes, project

#include <hugh/scene/object/texture/base.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace texture {
      
        // types, exported (class, enum, struct, union, typedef)

        class HUGH_SCENE_EXPORT d2 : public base {

        public:

          explicit d2(glm::uvec2 const&  /* size */  = default_size.xy(),
                      glm::uvec4 const&  /* color */ = default_color);
          explicit d2(std::string const& /* file */);
          virtual ~d2();

          virtual bool empty() const;
      
        private:

          gli::texture2d tdata_;
        
        };
      
        // variables, exported (extern)
      
        // functions, inlined (inline)
      
        // functions, exported (extern)

      } // namespace texture {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_TEXTURE_D2_HPP)
