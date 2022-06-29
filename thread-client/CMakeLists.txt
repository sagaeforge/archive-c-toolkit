cmake_minimum_required(VERSION 3.0.0)
project(ThreadClient VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ThreadClient main.c)
target_link_libraries(ThreadClient PUBLIC pthread)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)