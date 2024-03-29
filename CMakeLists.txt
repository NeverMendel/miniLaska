cmake_minimum_required(VERSION 3.10)
project(miniLaska C)

set(CMAKE_C_STANDARD 90)

option(BUILD_RELEASE "BUILD_RELEASE" ON)

set(miniLaskaSources "src/constants.h" "src/terminal.c" "src/terminal.h" "src/logic.c" "src/logic.h" "src/utility.c" "src/utility.h")

add_executable(miniLaska ${miniLaskaSources} src/main.c)
target_link_libraries(miniLaska m)

if (NOT ${BUILD_RELEASE})
    # Enable tests if run in debug mode
    enable_testing()

    file(GLOB TEST_SOURCES test/*.c)

    foreach (testsourcefile ${TEST_SOURCES})
        # Get file name
        string(REPLACE "/" ";" filePath ${testsourcefile})
        list(LENGTH filePath list_len)
        math(EXPR list_last "${list_len} - 1")
        list(GET filePath ${list_last} file_name)

        string(REPLACE ".c" "" testname ${file_name})
        add_executable(${testname} ${miniLaskaSources} test/${file_name})
        # Link math library
        target_link_libraries(${testname} m)
        # Add test
        add_test(${testname} ${testname})
    endforeach (testsourcefile ${TEST_SOURCES})
endif ()

if (${BUILD_RELEASE})
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3")
else()
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
endif()

add_definitions(-pedantic-errors)
