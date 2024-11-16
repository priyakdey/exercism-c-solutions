#ifndef PANGRAM_H
#define PANGRAM_H

#include <stdbool.h>

#define ALL_PRESENT 0x3FFFFFF

bool is_pangram(const char* sentence);

#endif
