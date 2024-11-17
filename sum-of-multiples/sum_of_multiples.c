#include "sum_of_multiples.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void populate_factors(const unsigned int factor, bool* buffer, size_t length) {
    unsigned int multiple = 1;
    unsigned int product;

    while ((product = factor * multiple) < length) {
        buffer[product] = true;
        multiple++;
    }
}

unsigned int sum(const unsigned int* factors, const size_t number_of_factors,
    const unsigned int limit) {

    // generate a buffer of limit + 1
    size_t length = limit;
    bool* buffer = (bool*)calloc(sizeof(bool), length);
    if (buffer == NULL) {
        fprintf(stderr, "Could not allocate memory: %s", strerror(errno));
        exit(1);
    }

    for (size_t i = 0; i < number_of_factors; i++) {
        if (factors[i] != 0) {
            populate_factors(factors[i], buffer, length);
        }
    }

    size_t sum = 0;
    for (size_t i = 0; i < length; i++) {
        if (buffer[i]) {
            sum += i;
        }
    }

    return sum;
}