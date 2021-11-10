cmake_minimum_required(VERSION 3.0.0)
project(GarbageCollection VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(GarbageCollection GarbageCollection.c)
target_include_directories(GarbageCollection PUBLIC ../../Includes/Public/)
target_include_directories(GarbageCollection PUBLIC ../../Includes/Private/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
