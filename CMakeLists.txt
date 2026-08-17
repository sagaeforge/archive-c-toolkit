cmake_minimum_required(VERSION 3.0.0)
project(NugungaModule VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
  NugungaModule
  
  init.c
  Sources/List/List.c
)

target_include_directories(NugungaModule PUBLIC Includes/Public Includes/Private )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
