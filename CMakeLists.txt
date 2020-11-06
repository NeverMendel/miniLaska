cmake_minimum_required(VERSION 3.16)
project(miniLaska C)

set(CMAKE_C_STANDARD 90)

add_executable(miniLaska src/main.c src/constants.h src/terminal.c src/terminal.h src/logic.c src/logic.h)