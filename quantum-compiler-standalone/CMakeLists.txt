cmake_minimum_required(VERSION 3.0.0)
project(Test2 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(
  Test2
  main.c
)

add_subdirectory(ProgramManager)


target_include_directories (
  Test2
  PUBLIC

  ProgramManager/Module/Exception/Includes/Public
  ProgramManager/Module/GarbageCollection/Includes/Public
  ProgramManager/Module/InputSystem/Includes/Public
  ProgramManager/Module/ProcessEvent/Includes/Public
)

target_link_libraries (
  Test2

  ProgramManager
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
