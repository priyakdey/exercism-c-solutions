#include "isogram.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
    if (phrase == NULL) return false;

    int field = 0;
    size_t length = strlen(phrase);

    for (size_t i = 0; i < length; i++) {
        char ch = phrase[i];
        if (ch == ' ' || ch == '-') continue;

        if (ch >= 65 && ch <= 90) {
            ch = ch ^ 32;
        }

        if (((field >> ((int)ch - 97)) & 1) == 1) {
            return false;
        }

        field = field | (1 << ((int)ch - 97));
    }

    return true;
}