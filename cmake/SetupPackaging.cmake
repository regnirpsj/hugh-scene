# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

INCLUDE(InstallRequiredSystemLibraries)

STRING(TOLOWER ${CMAKE_PROJECT_NAME} PACKAGE_PREFIX)

SET(CPACK_PACKAGE_NAME                "${PACKAGE_PREFIX}")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PACKAGE_PREFIX} infrastructure")
SET(CPACK_PACKAGE_VENDOR              "dcs.hull.ac.uk")
#SET(CPACK_PACKAGE_DESCRIPTION_FILE    "${CMAKE_CURRENT_SOURCE_DIR}/README.rst")
SET(CPACK_RESOURCE_FILE_LICENSE       "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
SET(CPACK_PACKAGE_VERSION_MAJOR       "0")
SET(CPACK_PACKAGE_VERSION_MINOR       "1")
SET(CPACK_PACKAGE_VERSION_PATCH       "0")
SET(CPACK_INCLUDE_TOPLEVEL_DIRECTORY  0)

SET(CPACK_COMPONENTS_ALL app doc hdr lib)

SET(CPACK_COMPONENT_APP_DISPLAY_NAME "Applications")
SET(CPACK_COMPONENT_DOC_DISPLAY_NAME "Documentation")
SET(CPACK_COMPONENT_HDR_DISPLAY_NAME "C++ Header")
SET(CPACK_COMPONENT_LIB_DISPLAY_NAME "Libraries")
SET(CPACK_COMPONENT_APP_DEPENDS       lib)
SET(CPACK_COMPONENT_HDR_DEPENDS       lib)
SET(CPACK_COMPONENT_APP_GROUP "app")
SET(CPACK_COMPONENT_DOC_GROUP "doc")
SET(CPACK_COMPONENT_HDR_GROUP "devel")
SET(CPACK_COMPONENT_LIB_GROUP "lib")

SET(CPACK_SOURCE_IGNORE_FILES "/.git/" ".gitignore" ".#" "/#" ".*~" "/build.*/")

# see [http://www.cmake.org/Wiki/CMake:CPackPackageGenerators]
IF(WIN32 OR WIN64)
  MESSAGE(STATUS "Creating NSIS package-installer configuration")

  SET(CPACK_GENERATOR "NSIS")
ELSEIF(UNIX)
  MESSAGE(STATUS "Creating RPM package-installer configuration")

  SET(CPACK_GENERATOR                "RPM")
  SET(CPACK_SOURCE_GENERATOR         "RPM")
  SET(CPACK_RPM_COMPRESSION_TYPE     bzip2)
  # SET(CPACK_RPM_PACKAGE_ARCHITECTURE ${ARCH})
  SET(CPACK_RPM_COMPONENT_INSTALL    ON)
  SET(CPACK_RPM_PACKAGE_RELEASE      1)
  SET(CPACK_RPM_PACKAGE_LICENSE      "LGPLv2")
  SET(CPACK_RPM_PACKAGE_GROUP        "Development/Libraries")
  SET(CPACK_RPM_PACKAGE_DEBUG        OFF)
ELSE()
  MESSAGE(SEND_ERROR "Unsupported platform for creating package installer")
ENDIF()

INCLUDE(CPack)
