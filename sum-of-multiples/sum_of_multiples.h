#ifndef SUM_OF_MULTIPLES_H
#define SUM_OF_MULTIPLES_H

#include <stdbool.h>
#include <stddef.h>

void populate_factors(const unsigned int factor, bool* buffer, size_t length);

unsigned int sum(const unsigned int* factors, const size_t number_of_factors,
    const unsigned int limit);


#endif
