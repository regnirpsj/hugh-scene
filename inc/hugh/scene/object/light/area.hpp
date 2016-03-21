// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/area.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_LIGHT_AREA_HPP)

#define HUGH_SCENE_OBJECT_LIGHT_AREA_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/light/spot.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT area : public spot {

        public:      

          using rep = base::rep;
      
          static area const dflt_light;

          field::value::single<glm::uvec2> size;    //< size.xy
          field::value::single<glm::uvec2> samples; //< samples.xy
      
          explicit area();
      
        protected:

          virtual void do_evaluate();
          virtual void do_changed(field::base&);

        private:

          rep  rep_;
          bool rebuild_;

          void rebuild();
        
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_LIGHT_AREA_HPP)
