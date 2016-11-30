# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS filesystem thread)
find_package(GLI   ${GLI_MINIMUM_VERSION}   REQUIRED)
find_package(GLM   ${GLM_MINIMUM_VERSION}   REQUIRED)
find_package(HUGH                           REQUIRED COMPONENTS field gli glm support)

include_directories(SYSTEM ${Boost_INCLUDE_DIR})
include_directories(SYSTEM ${GLI_INCLUDE_DIR})
include_directories(SYSTEM ${GLM_INCLUDE_DIR})
include_directories(SYSTEM ${HUGH_INCLUDE_DIRS})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

if(VERBOSE)
  find_package(OpenMP)
else()
  find_package(OpenMP QUIET)
endif()
if(OPENMP_FOUND)
  if(NOT VERBOSE)
    message(STATUS "Using OpenMP: ${OpenMP_CXX_FLAGS}")
  endif()
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(SRC)

list(APPEND SRC file.cpp)

list(APPEND SRC loader/mtl.cpp)
list(APPEND SRC loader/obj.cpp)
list(APPEND SRC loader/xform.cpp)

list(APPEND SRC node/base.cpp)
list(APPEND SRC node/camera.cpp)
list(APPEND SRC node/dynamic.cpp)
list(APPEND SRC node/geometry.cpp)
list(APPEND SRC node/global_light.cpp)
list(APPEND SRC node/group.cpp)
list(APPEND SRC node/local_light.cpp)
list(APPEND SRC node/material_group.cpp)
list(APPEND SRC node/rotor.cpp)
list(APPEND SRC node/select.cpp)
list(APPEND SRC node/transform.cpp)
list(APPEND SRC node/translator.cpp)

list(APPEND SRC object/base.cpp)

list(APPEND SRC object/camera/base.cpp)
list(APPEND SRC object/camera/frustum.cpp)
list(APPEND SRC object/camera/orthographic.cpp)
list(APPEND SRC object/camera/perspective.cpp)
list(APPEND SRC object/camera/viewport.cpp)

list(APPEND SRC object/geometry/attribute.cpp)
list(APPEND SRC object/geometry/base.cpp)
list(APPEND SRC object/geometry/cube.cpp)
list(APPEND SRC object/geometry/cylinder.cpp)
list(APPEND SRC object/geometry/icosahedron.cpp)
list(APPEND SRC object/geometry/mesh.cpp)
list(APPEND SRC object/geometry/octahedron.cpp)
list(APPEND SRC object/geometry/sphere.cpp)
#list(APPEND SRC object/geometry/triangle.cpp)
list(APPEND SRC object/geometry/tetrahedron.cpp)

list(APPEND SRC object/light/area.cpp)
list(APPEND SRC object/light/base.cpp)
list(APPEND SRC object/light/directional.cpp)
list(APPEND SRC object/light/positional.cpp)
list(APPEND SRC object/light/spot.cpp)

list(APPEND SRC object/material/base.cpp)
list(APPEND SRC object/material/simple.cpp)
list(APPEND SRC object/material/textured.cpp)

list(APPEND SRC object/texture/base.cpp)
list(APPEND SRC object/texture/d1.cpp)
list(APPEND SRC object/texture/d2.cpp)
list(APPEND SRC object/texture/d3.cpp)
list(APPEND SRC object/texture/fill.cpp)
list(APPEND SRC object/texture/load.cpp)

list(APPEND SRC visitor/base.cpp)
list(APPEND SRC visitor/bfs.cpp)
#list(APPEND SRC visitor/collect.cpp)
list(APPEND SRC visitor/cull.cpp)
list(APPEND SRC visitor/dfs.cpp)
#list(APPEND SRC visitor/intersect.cpp)
list(APPEND SRC visitor/print.cpp)
list(APPEND SRC visitor/subject.cpp)
list(APPEND SRC visitor/update_bounds.cpp)

#add_definitions(-DHUGH_ALL_TRACE)

set(LIBS)
list(APPEND LIBS ${HUGH_LIBRARIES})
list(APPEND LIBS ${Boost_LIBRARIES})

set(LIB hugh_scene)

cma_setup_library(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS} INCDIR hugh/scene)
cma_setup_export(${LIB})

add_subdirectory(test EXCLUDE_FROM_ALL)
