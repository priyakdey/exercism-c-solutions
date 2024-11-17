#include "sieve.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t sieve(uint32_t limit, uint32_t* primes, size_t max_primes) {
    bool* sieve = (bool*)calloc(sizeof(bool), limit + 1);
    sieve[0] = true;
    sieve[1] = true;
    uint32_t prime_count = limit - 2;

    for (uint32_t i = 2; i <= limit; i++) {
        if (sieve[i]) continue;

        for (uint32_t j = 2; i * j <= limit; j++) {
            sieve[i * j] = true;
            prime_count--;
        }
    }

    size_t cursor = 0;
    for (uint32_t i = 0; i <= limit; i++) {
        if (!sieve[i]) {
            primes[cursor++] = i;
        }

        if (cursor == max_primes) {
            break;
        }
    }

    return cursor;
}