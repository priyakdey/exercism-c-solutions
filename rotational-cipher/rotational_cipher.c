#include "rotational_cipher.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* rotate(const char* text, int shift_key) {
    size_t length = strlen(text);
    // TODO: +1 for NULL termination. dividing the size and multiping looks stupid,
    // but for now we are learning, not building for performance.
    // Check how much extra instructions are being generated for this extra step.
    size_t allocation_size = (sizeof(char) * (length / sizeof(char))) + 1;

    char* encoded_text = (char*)malloc(sizeof(char) * allocation_size);
    if (encoded_text == NULL) {
        fprintf(stderr, "Could not allocate memory");
        exit(1);
    }

    for (size_t i = 0; i < length; i++) {
        int ord = (int)text[i];
        if (ord >= 65 && ord <= 90) {
            ord = (((ord - 65) + shift_key) % 26) + 65;
        }
        else if (ord >= 97 && ord <= 122) {
            ord = (((ord - 97) + shift_key) % 26) + 97;
        }
        printf("%d - %c\n", ord, (char)ord);
        encoded_text[i] = (char)ord;
    }

    // null terminated cstr!!
    encoded_text[length] = '\0';
    return encoded_text;
}
