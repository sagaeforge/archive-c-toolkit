cmake_minimum_required(VERSION 3.0.0)
project(NLB_Utility VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
  NLB_Utilitiy

  init.c
)

add_subdirectory(DevelopGuide)
add_subdirectory(GarbageCollection)
add_subdirectory(LinearDataTypes)
add_subdirectory(Operator)
add_subdirectory(String)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
