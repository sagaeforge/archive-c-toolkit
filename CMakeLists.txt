cmake_minimum_required(VERSION 3.0.0)
project(NugungaUtilities VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  NugungaUtilities
  
  test.c
)
add_subdirectory(GarbageCollection)

target_include_directories(NugungaUtilities PUBLIC GarbageCollection)
target_link_libraries(NugungaUtilities GarbageCollection)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
