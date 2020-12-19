cmake_minimum_required(VERSION 3.10)
project(miniLaska C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} -O3")

set(miniLaskaSources "src/constants.h" "src/terminal.c" "src/terminal.h" "src/logic.c" "src/logic.h" "src/utility.c" "src/utility.h")

add_executable(miniLaska ${miniLaskaSources} src/main.c)

add_executable(apply_move_test ${miniLaskaSources} test/apply_move_test.c)
add_executable(clone_board_test ${miniLaskaSources} test/clone_board_test.c)
add_executable(compute_state_test ${miniLaskaSources} test/compute_state_test.c)
add_executable(does_move_eat_test ${miniLaskaSources} test/does_move_eat_test.c)
add_executable(get_index_from_coordinates_test ${miniLaskaSources} test/get_index_from_coordinates_test.c)
add_executable(get_possible_moves_test ${miniLaskaSources} test/get_possible_moves.c)
add_executable(is_pos_valid_test ${miniLaskaSources} test/is_pos_valid_test.c)

enable_testing()

add_test(apply_move_test apply_move_test)
add_test(clone_board_test clone_board_test)
add_test(compute_state_test compute_state_test)
add_test(does_move_eat_test does_move_eat_test)
add_test(get_index_from_coordinates_test get_index_from_coordinates_test)
add_test(get_possible_moves_test get_possible_moves_test)
add_test(is_pos_valid_test is_pos_valid_test)

add_definitions(-pedantic-errors)
