#include "luhn.h"

#include <ctype.h>
#include <string.h>

void strip_whitespace(const char* num, size_t length, size_t* left, size_t* right) {
    *left = 0;
    while (*left < length && isspace(num[*left])) {
        (*left)++;
    }

    *right = length - 1;
    while (*right < length && isspace(num[*right])) {
        (*right)--;
    }
}

bool luhn(const char* num) {
    size_t length = strlen(num);
    if (length <= 1) return false;

    size_t left, right;
    strip_whitespace(num, length, &left, &right);
    if (left == length) {
        return false;
    }

    int sum = 0;
    int skip = false;
    while (left <= right) {
        char ch = num[left];
        left++;
        if (isdigit(ch) == 1) return false;
        if (isspace(ch)) continue;

        int digit = (int)ch - 48;

        if (!skip) {
            digit = digit * 2;
            if (digit > 9) {
                digit = 12 - digit;
            }
        }
        sum += digit;
        skip = !skip;

    }

    return sum % 10 == 0;
}