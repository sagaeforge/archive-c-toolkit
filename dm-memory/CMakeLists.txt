cmake_minimum_required(VERSION 3.0.0)
project(DynamicMemory VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

set ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../bin )

add_library (
    DynamicMemory

    Sources/Dmem_allFree.c
    Sources/Dmem_append.c
    Sources/Dmem_Manager.c
    Sources/DmemPage_AllElementsFree.c
    Sources/DmemPage_ElementFree.c
    Sources/DmemPage_Page.c
    Sources/Dmem_remove.c
    Sources/File_Close.c
    Sources/File_Open.c
    Sources/LogSave.c
    Sources/MemoryAlloc.c
    Sources/MemoryFree.c
    Sources/SimpleAlloc.c
)

target_include_directories( DynamicMemory PUBLIC ${CMAKE_SOURCE_DIR}/Includes )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
