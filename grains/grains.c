#include "grains.h"

uint64_t square(uint8_t index) {
    return index > 0 && index < 65 ? 1ULL << (index - 1) : 0;
}

uint64_t total(void) {
    uint64_t total = 0;
    for (uint64_t i = 1; i < 65; i++) {
        total += 1ULL << (i - 1);
    }

    return total;
}