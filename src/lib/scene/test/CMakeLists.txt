# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

cma_print_current_directory()

find_package(Boost ${BOOST_MINIMUM_VERSION} REQUIRED COMPONENTS unit_test_framework)

include_directories(SYSTEM ${Boost_INLCUDE_DIR})
include_directories(       ${CMAKE_CURRENT_SOURCE_DIR})

set(SRC)
LIST(APPEND SRC "file.cpp")
LIST(APPEND SRC "loader_mtl.cpp")
LIST(APPEND SRC "loader_obj.cpp")
LIST(APPEND SRC "loader_xform.cpp")
LIST(APPEND SRC "node_camera.cpp")
LIST(APPEND SRC "node_global_light.cpp")
LIST(APPEND SRC "node_group.cpp")
LIST(APPEND SRC "node_local_light.cpp")
LIST(APPEND SRC "node_material_group.cpp")
LIST(APPEND SRC "node_mesh.cpp")
LIST(APPEND SRC "node_rotor.cpp")
LIST(APPEND SRC "node_select.cpp")
LIST(APPEND SRC "node_transform.cpp")
LIST(APPEND SRC "node_translator.cpp")
LIST(APPEND SRC "object_camera.cpp")
LIST(APPEND SRC "object_light.cpp")
LIST(APPEND SRC "object_material.cpp")
LIST(APPEND SRC "object_texture.cpp")
LIST(APPEND SRC "primitive_cube.cpp")
LIST(APPEND SRC "primitive_cylinder.cpp")
LIST(APPEND SRC "primitive_icosahedron.cpp")
LIST(APPEND SRC "primitive_octahedron.cpp")
LIST(APPEND SRC "primitive_sphere.cpp")
LIST(APPEND SRC "primitive_tetrahedron.cpp")

set(LIBS)
list(APPEND LIBS ${LIB})
list(APPEND LIBS ${Boost_LIBRARIES})

cma_setup_test(${LIB} SOURCES ${SRC} DEPENDENCIES ${LIBS})

# test w/ add'l (shared) objects
set(SRC)
list(APPEND SRC "visitor_cull.cpp")
list(APPEND SRC "visitor_print.cpp")
list(APPEND SRC "visitor_update_bounds.cpp")

set(SHRD)
list(APPEND SHRD "visitor_shared.cpp")

cma_setup_test(${LIB} SOURCES ${SRC} ADDITIONAL ${SHRD} DEPENDENCIES ${LIBS})
