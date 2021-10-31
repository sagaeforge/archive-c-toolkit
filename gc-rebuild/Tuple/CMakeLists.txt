cmake_minimum_required(VERSION 3.0.0)
project(Tuples VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Tuples Tuple.c)

set_target_properties(Tuples PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ../Output)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
