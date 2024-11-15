#include "binary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(const char* input) {
    size_t len = strlen(input);

    int number = 0;

    for (size_t i = 0; i < len; i++) {
        char ch = input[i];
        if (ch == '0') {
            continue;
        }
        else if (ch == '1') {
            number += 1 << (len - i - 1);   // little endian
        }
        else {
            return INVALID;
        }
    }
    printf("\n");
    return number;
}
