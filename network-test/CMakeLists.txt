cmake_minimum_required(VERSION 3.0.0)
project(tcp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(tcp main.cpp)
target_link_libraries(tcp PUBLIC ws2_32.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
