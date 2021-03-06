# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework system)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
LIST(APPEND SRC file.cpp)

LIST(APPEND SRC loader_mtl.cpp)
LIST(APPEND SRC loader_obj.cpp)
LIST(APPEND SRC loader_xform.cpp)

LIST(APPEND SRC node_camera.cpp)
LIST(APPEND SRC node_geometry.cpp)
LIST(APPEND SRC node_global_light.cpp)
LIST(APPEND SRC node_group.cpp)
LIST(APPEND SRC node_local_light.cpp)
LIST(APPEND SRC node_material_group.cpp)
LIST(APPEND SRC node_rotor.cpp)
LIST(APPEND SRC node_select.cpp)
LIST(APPEND SRC node_transform.cpp)
LIST(APPEND SRC node_translator.cpp)

LIST(APPEND SRC object_camera_frustum.cpp)
LIST(APPEND SRC object_camera_orthographic.cpp)
LIST(APPEND SRC object_camera_perspective.cpp)
LIST(APPEND SRC object_camera_viewport.cpp)

LIST(APPEND SRC object_geometry_cube.cpp)
LIST(APPEND SRC object_geometry_cylinder.cpp)
LIST(APPEND SRC object_geometry_icosahedron.cpp)
LIST(APPEND SRC object_geometry_mesh.cpp)
LIST(APPEND SRC object_geometry_octahedron.cpp)
LIST(APPEND SRC object_geometry_sphere.cpp)
LIST(APPEND SRC object_geometry_tetrahedron.cpp)

LIST(APPEND SRC object_light_area.cpp)
LIST(APPEND SRC object_light_directional.cpp)
LIST(APPEND SRC object_light_positional.cpp)
LIST(APPEND SRC object_light_rep.cpp)
LIST(APPEND SRC object_light_spot.cpp)

LIST(APPEND SRC object_material_simple.cpp)
LIST(APPEND SRC object_material_textured.cpp)

LIST(APPEND SRC object_textures.cpp)

add_definitions(-DGLI_ROOT_DIR=${GLI_ROOT_DIR})
add_definitions(-DCMAKE_INSTALL_PREFIX=\"${CMAKE_INSTALL_PREFIX}\")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

# test w/ add'l (shared) objects
set(SRC)
list(APPEND SRC visitor_cull.cpp)
list(APPEND SRC visitor_print.cpp)
list(APPEND SRC visitor_update_bounds.cpp)

set(SHRD)
list(APPEND SHRD visitor_shared.cpp)

cma_setup_test(${LIB} SOURCES ${SRC} ADDITIONAL ${SHRD} DEPENDENCIES ${LIBS})
