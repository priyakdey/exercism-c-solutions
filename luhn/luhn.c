#include "luhn.h"

#include <ctype.h>
#include <string.h>

bool luhn(const char* num) {
    size_t length = strlen(num);
    if (length < 2) return false;

    bool doubleit = false;
    int total_sum = 0;
    int valid_digit_count = 0;

    for (size_t i = length - 1; i < length; i--) {
        char ch = num[i];
        if (ch == ' ') {
            continue;
        }
        else if (!isdigit(ch)) {
            return false;
        }
        else {
            int digit = (int)ch - 48;
            if (doubleit) digit = digit * 2;
            if (digit > 9) digit = digit - 9;

            total_sum += digit;
            doubleit = !doubleit;
            valid_digit_count++;
        }
    }

    return valid_digit_count > 1 && total_sum % 10 == 0;
}