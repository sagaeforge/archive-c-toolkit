cmake_minimum_required(VERSION 3.0.0)
project(GarbageCollection VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
  GarbageCollection

  GC_Init.c
  GCClean.c
  GCClear.c
  GCManagerInit.c
  Memory.c
  MemoryGet.c
  MemoryGetLength.c
  MemoryPageAppend.c
  MemoryPageGet.c
  MemoryPageGetEmpty.c
  MemoryPageGetLast.c
  MemoryPageMemoryRemove.c
  MemoryPageRemove.c
  MemorySearch.c
)

target_include_directories(GarbageCollection PUBLIC ../../Includes/Public ../../Includes/Private)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
