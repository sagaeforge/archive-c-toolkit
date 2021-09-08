cmake_minimum_required(VERSION 3.0.0)
project(String VERSION 0.1.0)

include(CTest)
enable_testing()



add_executable(
    String

    Sources/String_Constructor.c
    Sources/String_Desctructor.c
    Sources/String_get.c
    Sources/String_set.c
    Sources/String_Operator.c
    Sources/String_contains.c
    Sources/String_isEmpty.c
    Sources/String_count.c
    Sources/String_join.c
    Sources/String_index.c
    Sources/__String.c

    main.c
)

target_include_directories( String PUBLIC ${CMAKE_SOURCE_DIR}/Includes )
target_include_directories( String PUBLIC ${CMAKE_SOURCE_DIR}/lib/Includes )
target_link_libraries( String ${CMAKE_SOURCE_DIR}/lib/libDynamicMemory.a )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
