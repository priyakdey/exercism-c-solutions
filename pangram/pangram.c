#include "pangram.h"

#include <stdlib.h>
#include <string.h>

bool is_pangram(const char* sentence) {
    if (sentence == NULL) return false;

    size_t length = strlen(sentence);
    int bitfield = 0;

    for (size_t i = 0; i < length; i++) {
        char ch = sentence[i];
        if (ch >= 65 && ch <= 90) {
            ch = ch ^ 32;
        }

        if (ch >= 97 && ch <= 122) {
            bitfield = bitfield | (1 << ((int)ch - 97));
        }

        if (bitfield == ALL_PRESENT) {
            return true;
        }
    }

    return false;
}