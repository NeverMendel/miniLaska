#include <stdio.h>
#include "../src/logic.h"

void test_get_index_from_coordinates_zero() {
    assert(0 == get_index_from_coordinates(0, 0));
}

void test_get_index_from_coordinates_four() {
    assert(4 == get_index_from_coordinates(1, 1));
}

void test_get_index_from_coordinates_five() {
    assert(5 == get_index_from_coordinates(3, 1));
}

void test_get_index_from_coordinates_seven() {
    assert(7 == get_index_from_coordinates(0, 2));
}

void test_get_index_from_coordinates_ten() {
    assert(10 == get_index_from_coordinates(6, 2));
}

void test_get_index_from_coordinates_twenty_four() {
    assert(24 == get_index_from_coordinates(6, 6));
}

void test_get_pos_from_index_seven() {
    Pos expected = initialize_pos(0, 2);
    Pos actual = get_pos_from_index(7);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_nine() {
    Pos expected = initialize_pos(4, 2);
    Pos actual = get_pos_from_index(9);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_ten() {
    Pos expected = initialize_pos(6, 2);
    Pos actual = get_pos_from_index(10);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_twelve() {
    Pos expected = initialize_pos(3, 3);
    Pos actual = get_pos_from_index(12);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_seventeen() {
    Pos expected = initialize_pos(6, 4);
    Pos actual = get_pos_from_index(17);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_twenty_one() {
    Pos expected = initialize_pos(0, 6);
    Pos actual = get_pos_from_index(21);
    assert(true == is_pos_equal(expected, actual));
}

void test_get_pos_from_index_twenty_four() {
    Pos expected = initialize_pos(6, 6);
    Pos actual = get_pos_from_index(24);
    assert(true == is_pos_equal(expected, actual));
}

int main() {
    test_get_index_from_coordinates_zero();
    test_get_index_from_coordinates_four();
    test_get_index_from_coordinates_five();
    test_get_index_from_coordinates_seven();
    test_get_index_from_coordinates_ten();
    test_get_index_from_coordinates_twenty_four();

    test_get_pos_from_index_seven();
    test_get_pos_from_index_nine();
    test_get_pos_from_index_ten();
    test_get_pos_from_index_twelve();
    test_get_pos_from_index_seventeen();
    test_get_pos_from_index_twenty_one();
    test_get_pos_from_index_twenty_four();

    return 0;
}
