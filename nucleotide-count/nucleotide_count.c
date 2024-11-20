#include "nucleotide_count.h"

#include <stdio.h>
#include <string.h>

#define DELIMTER ':'


size_t digit_count(size_t number) {
    if (number == 0) return 1;

    size_t digit_count = 0;

    while (number > 0) {
        digit_count++;
        number = number / 10;
    }

    return digit_count;
}

char* count(const char* dna_strand) {
    size_t length = strlen(dna_strand);

    size_t a = 0, c = 0, g = 0, t = 0;

    for (size_t i = 0; i < length; i++) {
        char nucleotide = dna_strand[i];
        switch (nucleotide) {
        case 'A': {
            a++;
            break;
        }
        case 'C': {
            c++;
            break;
        }
        case 'G': {
            g++;
            break;
        }
        case 'T': {
            t++;
            break;
        }
        default: {
            char* buf = (char*)malloc(sizeof(char) * 1);
            buf[0] = '\0';
            return buf;
        }
        }
    }

    size_t a_digit_count = digit_count(a);
    size_t c_digit_count = digit_count(c);
    size_t g_digit_count = digit_count(g);
    size_t t_digit_count = digit_count(t);

    size_t total_digits = a_digit_count + c_digit_count + g_digit_count + t_digit_count;
    size_t total_length = 4 + 4 + 3 + total_digits + 1;

    char* buf = (char*)malloc(sizeof(char) * total_length);

    sprintf(buf, "A:%zu C:%zu G:%zu T:%zu", a, c, g, t);
    return buf;
}