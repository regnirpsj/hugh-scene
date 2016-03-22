// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/texture/d1.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_TEXTURE_D1_HPP)

#define HUGH_SCENE_OBJECT_TEXTURE_D1_HPP

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

        class HUGH_SCENE_EXPORT d1 : public base {

        public:

          explicit d1(unsigned const&    /* size */  = default_size.x,
                      glm::uvec4 const&  /* color */ = default_color);
          explicit d1(std::string const& /* file */);
          virtual ~d1();

          virtual bool empty() const;

          virtual void print_on(std::ostream&) const;
          
        private:

          gli::texture1d tdata_;
        
        };
      
        // variables, exported (extern)
      
        // functions, inlined (inline)
      
        // functions, exported (extern)

      } // namespace texture {

    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_TEXTURE_D1_HPP)
