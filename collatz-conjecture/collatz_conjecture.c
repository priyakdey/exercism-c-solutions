#include "collatz_conjecture.h"

int steps(int start) {
    if (start <= 0) return ERROR_VALUE;

    int steps = 0;

    while (start != 1) {
        steps++;

        if ((start & 1) == 0) {
            start = start / 2;
        }
        else {
            start = 3 * start + 1;
        }
    }

    return steps;
}