#include "eliuds_eggs.h"

unsigned int egg_count(int display) {
    unsigned int eggs = 0;
    for (int i = 0; i < 32; i++) {
        eggs += display & 1;
        display = display >> 1;
    }

    return eggs;
}