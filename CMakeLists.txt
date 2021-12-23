cmake_minimum_required(VERSION 3.0.0)
project(ProgramManager VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  ProgramManager
  Sources/Delegate.c
  Sources/ProgramManager.c
  Main.c
)

target_include_directories(ProgramManager PUBLIC Includes/)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
