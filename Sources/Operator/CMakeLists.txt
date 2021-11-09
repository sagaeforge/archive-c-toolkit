cmake_minimum_required(VERSION 3.0.0)
project(Operator VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Operator Operator.c)
target_include_directories(Operator PUBLIC ../../Includes/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
