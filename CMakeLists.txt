cmake_minimum_required(VERSION 3.0.0)
project(NugungaUtilities VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  NugungaUtilities
  
  test.c
)

ADD_COMPILE_OPTIONS(-g -Wall) 
SET ( CMAKE_VERBOSE_MAKEFILE true )

add_subdirectory(GarbageCollection)
add_subdirectory(Nugunga_Error)
add_subdirectory(Nugunga_List)
add_subdirectory(Nugunga_String)

target_include_directories(NugungaUtilities PUBLIC GarbageCollection)
target_link_libraries(NugungaUtilities GarbageCollection)

target_include_directories(NugungaUtilities PUBLIC Nugunga_Error)
target_link_libraries(NugungaUtilities Nugunga_Error)

target_include_directories(NugungaUtilities PUBLIC Nugunga_List)
target_link_libraries(NugungaUtilities Nugunga_List)

target_include_directories(NugungaUtilities PUBLIC Nugunga_String)
target_link_libraries(NugungaUtilities Nugunga_String)

set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Out)
set_target_properties(NugungaUtilities PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/Out)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
 