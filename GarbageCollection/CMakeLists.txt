cmake_minimum_required(VERSION 3.0.0)
project(GarbageCollection VERSION 0.1.0)

include(CTest)
enable_testing()

add_library (
  GarbageCollection
  STATIC
  GC.c
)

set(ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../Out)
set_target_properties(GarbageCollection PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../Out)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
