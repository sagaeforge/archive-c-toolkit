cmake_minimum_required(VERSION 3.0.0)
project(Nugunga_Error VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
  Nugunga_Error 
  NError.c
)

set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../Out/Lib)
set_target_properties(Nugunga_Error PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../Out/Lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
