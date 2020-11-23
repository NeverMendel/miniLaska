cmake_minimum_required(VERSION 3.10)
project(miniLaska C)

set(CMAKE_C_STANDARD 90)

add_executable(miniLaska src/main.c src/constants.h src/terminal.c src/terminal.h src/logic.c src/logic.h src/utility.c src/utility.h)

add_executable(tests src/constants.h src/logic.c src/logic.h src/utility.h src/utility.c test/logic_test.c test/minunit.h)

add_definitions(-pedantic-errors)
