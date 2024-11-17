#include "reverse_string.h"

#include <stdlib.h>
#include <string.h>

char* reverse(const char* value) {
    size_t length = strlen(value);

    char* reversed = (char*)malloc(sizeof(char) * (length + 1));

    for (int i = length - 1; i >= 0; i--) {
        reversed[length - i - 1] = value[i];
    }
    reversed[length] = '\0';
    return reversed;
}