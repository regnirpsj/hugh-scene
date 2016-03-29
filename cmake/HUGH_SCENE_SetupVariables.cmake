# -*- Mode:cmake -*-

####################################################################################################
#                                                                                                  #
# Copyright (C) 2016 University of Hull                                                            #
#                                                                                                  #
####################################################################################################

if(VERBOSE)
  message(STATUS "Loading ${PROJECT_NAME} variables")
endif()

include(CMakeAddons_SetupVariables)

set(${PROJECT_NAME}_COVERAGE_EXCLUDE "${${PROJECT_NAME}_COVERAGE_EXCLUDE} 'install/*'")
