cmake_minimum_required(VERSION 3.0.0)
project(ProcessEvent VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(
  ProcessEvent
  Sources/ProcessEvent.c
  Sources/Awake_ProcessEvent.c
  Sources/Init_ProcessEvent.c
  Sources/Start_ProcessEvent.c
  Sources/Main_ProcessEvent.c
  Sources/Quit_ProcessEvent.c
  Sources/Update_ProcessEvent.c
  Sources/FixedUpdate_ProcessEvent.c
)

target_include_directories(
  ProcessEvent
  PUBLIC

  # 모듈들
  ../Exception/Includes/Public
  ../GarbageCollection/Includes/Public
  ../InputSystem/Includes/Public
  ../ProcessEvent/Includes/Public

  # 상위 프로젝트의 헤더 참조
  ../../Includes/

  Includes/Private
)

target_link_libraries(
  ProcessEvent
  pthread
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)