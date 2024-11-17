#include "square_root.h"

uint16_t square_root(uint16_t number) {
    uint16_t sqrt = 0;
    uint16_t left = 1, right = (number / 2) + 1;

    while (left <= right) {
        uint16_t mid = (right + left) / 2;
        if (mid * mid <= number) {
            sqrt = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return sqrt;
}