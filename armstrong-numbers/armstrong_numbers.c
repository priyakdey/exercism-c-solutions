#include "armstrong_numbers.h"

#include <math.h>

bool is_armstrong_number(int candidate) {
    // >>> len(str((1 << 31) - 1))
    // 10
    int buffer[10] = { 0 };
    int cursor = 0;
    int copy = candidate;

    while (copy > 0) {
        buffer[cursor++] = copy % 10;
        copy = copy / 10;
    }

    int total_sum = 0;
    for (int i = 0; i < cursor; i++) {
        total_sum += (int)pow(buffer[i], cursor);
    }

    return total_sum == candidate;
}