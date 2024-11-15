#include "queen_attack.h"

#include <stdio.h>

bool is_valid_position(position_t queen) {
    return queen.row < ROWS && queen.column < COLS;
}

attack_status_t can_attack(position_t queen_1, position_t queen_2) {
    if (queen_1.row == queen_2.row && queen_1.column == queen_2.column) {
        return INVALID_POSITION;
    }

    if (!is_valid_position(queen_1) || !is_valid_position(queen_2)) {
        return INVALID_POSITION;
    }

    if (queen_1.row == queen_2.row) {
        return CAN_ATTACK;
    }

    if (queen_1.column == queen_2.column) {
        return CAN_ATTACK;
    }

    int row, col;

    // bottom right
    row = queen_1.row;
    col = queen_1.column;
    while (row < ROWS && col < COLS && row != queen_2.row && col != queen_2.column) {
        row++;
        col++;
    }

    if (row == queen_2.row && col == queen_2.column) {
        return CAN_ATTACK;
    }

    // bottom left
    row = queen_1.row;
    col = queen_1.column;
    while (row < ROWS && row != queen_2.row && col != queen_2.column) {
        row++;
        col--;
    }

    if (row == queen_2.row && col == queen_2.column) {
        return CAN_ATTACK;
    }

    // top left
    row = queen_1.row;
    col = queen_1.column;
    while (row > 0 && row != queen_2.row && col != queen_2.column) {
        row--;;
        col--;
    }

    if (row == queen_2.row && col == queen_2.column) {
        return CAN_ATTACK;
    }

    // top right
    row = queen_1.row;
    col = queen_1.column;
    while (col < COLS && row != queen_2.row && col != queen_2.column) {
        row--;;
        col++;
    }

    printf("%d-%d\n", queen_1.row, queen_2.column);

    if (row == queen_2.row && col == queen_2.column) {
        return CAN_ATTACK;
    }

    return CAN_NOT_ATTACK;
}