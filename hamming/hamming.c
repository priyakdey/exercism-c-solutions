#include "hamming.h"

#include <stdlib.h>
#include <string.h>

int compute(const char* lhs, const char* rhs) {
    size_t length = strlen(lhs);
    if (length != strlen(rhs)) {
        return ERROR_CODE;
    }

    int hamming_distance = 0;

    for (size_t i = 0; i < length; i++) {
        if (lhs[i] != rhs[i]) {
            hamming_distance++;
        }
    }

    return hamming_distance;
}