// -*- Mode:C++ -*-

/**************************************************************************************************/
/*                                                                                                */
/* Copyright (C) 2016 University of Hull                                                          */
/*                                                                                                */
/**************************************************************************************************/
/*                                                                                                */
/*  module     :  hugh/scene/object/light/spot.hpp                                                */
/*  project    :                                                                                  */
/*  description:                                                                                  */
/*                                                                                                */
/**************************************************************************************************/

#if !defined(HUGH_SCENE_OBJECT_LIGHT_SPOT_HPP)

#define HUGH_SCENE_OBJECT_LIGHT_SPOT_HPP

// includes, system

//#include <>

// includes, project

#include <hugh/scene/object/light/directional.hpp>
#include <hugh/scene/object/light/positional.hpp>

namespace hugh {
  
  namespace scene {

    namespace object {

      namespace light {
      
        // types, exported (class, enum, struct, union, typedef)

        struct HUGH_SCENE_EXPORT spot : public directional,
                                        public positional {

        public:      

          using rep = base::rep;
      
          static spot const dflt_light;

          field::value::single<float> exponent; //< spot exponent [0,127]
          field::value::single<float> cutoff;   //< spot cutoff   [0,90]|180
      
          explicit spot();
      
        protected:

          virtual void do_evaluate();
          virtual void do_changed(field::base&);
        
        };
    
        // variables, exported (extern)

        // functions, inlined (inline)
  
        // functions, exported (extern)

      } // namespace light {
    
    } // namespace object {
  
  } // namespace scene {

} // namespace hugh {

#endif // #if !defined(HUGH_SCENE_OBJECT_LIGHT_SPOT_HPP)
