#include "../src/logic.h"
#include "../src/utility.h"

void test_is_pos_valid_valid_pos1() {
    Pos pos = {4, 4};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    assert(expected == actual);
}

void test_is_pos_valid_valid_pos2() {
    Pos pos = {6, 0};
    bool expected = true;
    bool actual = is_pos_valid(pos);
    assert(expected == actual);
}

void test_is_pos_valid_out_of_bound() {
    Pos pos = {7, 2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    assert(expected == actual);
}

void test_is_pos_valid_not_used_cell1() {
    Pos pos = {1, 2};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    assert(expected == actual);
}

void test_is_pos_valid_not_used_cell2() {
    Pos pos = {3, 6};
    bool expected = false;
    bool actual = is_pos_valid(pos);
    assert(expected == actual);
}

int main() {
    test_is_pos_valid_valid_pos1();
    test_is_pos_valid_valid_pos2();
    test_is_pos_valid_out_of_bound();
    test_is_pos_valid_not_used_cell1();
    test_is_pos_valid_not_used_cell2();
}
