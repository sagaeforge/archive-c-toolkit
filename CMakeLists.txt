cmake_minimum_required(VERSION 3.0.0)
project(GC VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  GC 
  GCtest.c
  GC.c
  GCInit.c
  Funcs/GCFuncs.c
  Memory/GCMemory.c
  Memory/GCMemoryPage.c
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
