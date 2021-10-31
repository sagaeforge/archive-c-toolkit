cmake_minimum_required(VERSION 3.0.0)
project(GC VERSION 0.1.0)

include(CTest)
enable_testing()

add_subdirectory(Tuple)
add_executable(GC GCExcuteTest.c)

target_link_libraries(GC PUBLIC Tuples)
target_include_directories(GC PUBLIC Tuple)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
