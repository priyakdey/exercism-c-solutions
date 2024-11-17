#ifndef LUHN_H
#define LUHN_H

#include <stdbool.h>
#include <stdlib.h>

void strip_whitespace(const char* num, size_t length, size_t* left, size_t* right);

bool luhn(const char* num);

#endif
