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

int main() {
    test_get_index_from_coordinates_zero();
    test_get_index_from_coordinates_four();
    test_get_index_from_coordinates_five();
    test_get_index_from_coordinates_seven();
    test_get_index_from_coordinates_ten();
    test_get_index_from_coordinates_twenty_four();

    return 0;
}
