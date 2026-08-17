cmake_minimum_required(VERSION 3.0.0)
project(NugungaUtility VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Sources/GarbageCollection)
add_subdirectory(Sources/Operator)
add_subdirectory(Sources/String)

add_executable(NugungaUtility Init.c)

target_link_libraries(NugungaUtility PUBLIC GarbageCollection)
target_link_libraries(NugungaUtility PUBLIC Operator)
target_link_libraries(NugungaUtility PUBLIC String)
target_include_directories(NugungaUtility PUBLIC Includes/Public)
target_include_directories(NugungaUtility PUBLIC Includes/Private)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
