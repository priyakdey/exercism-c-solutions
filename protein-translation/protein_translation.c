#include "protein_translation.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_three_chars(const char* const rna, size_t length, char* buffer, size_t* cursor) {
    if (*cursor + 3 >= length) return -1;
    buffer[0] = rna[(*cursor)++];
    buffer[1] = rna[(*cursor)++];
    buffer[2] = rna[(*cursor)++];
    return 3;
}

proteins_t proteins(const char* const rna) {
    size_t length = strlen(rna);
    proteins_t protein = { 0 };
    char* buffer = (char*)malloc(sizeof(char) * 3);
    if (buffer == NULL) {
        fprintf(stderr, "could not allocate memory");
        exit(1);
    }
    size_t cursor = 0;

    size_t proteins_count = 0;
    protein_t* proteins = (protein_t*)malloc(sizeof(char) * MAX_PROTEINS);

    while (cursor < length) {
        int n = read_three_chars(rna, length, buffer, &cursor);
        if (n == -1) {
            printf("--- invalid read = %u - -----\n", *buffer);
            protein.valid = false;
            protein.count = 0;
            return protein;
        }

        if (strcmp("AUG", buffer) == 0) {
            proteins[proteins_count] = Methionine;
            proteins_count++;
        }
        else if (strcmp("UUU", buffer) == 0 || strcmp("UUC", buffer) == 0) {
            proteins[proteins_count] = Phenylalanine;
            proteins_count++;
        }
        else if (strcmp("UUA", buffer) == 0 || strcmp("UUG", buffer) == 0) {
            proteins[proteins_count] = Leucine;
            proteins_count++;
        }
        else if (strcmp("UCU", buffer) == 0
            || strcmp("UCC", buffer) == 0
            || strcmp("UCA", buffer) == 0
            || strcmp("UCG", buffer) == 0) {
            proteins[proteins_count] = Leucine;
            proteins_count++;
        }
        else if (strcmp("UAU", buffer) == 0 || strcmp("UAC", buffer) == 0) {
            proteins[proteins_count] = Tyrosine;
            proteins_count++;
        }
        else if (strcmp("UGU", buffer) == 0 || strcmp("UGC", buffer) == 0) {
            proteins[proteins_count] = Cysteine;
            proteins_count++;
        }
        else if (strcmp("UGG", buffer) == 0) {
            proteins[proteins_count] = Tryptophan;
            proteins_count++;
        }
        else {
            break;
        }
    }

    free(buffer);

    protein.valid = true;
    protein.count = proteins_count;

    memcpy(protein.proteins, proteins, proteins_count);

    printf("------ isvalid = %d, count = %zu, proteins = %u -----------\n", protein.valid, protein.count, *protein.proteins);

    return protein;
}