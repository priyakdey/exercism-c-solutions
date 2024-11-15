#include "rna_transcription.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DNA -> RNA
// G   -> C
// C   -> G
// T   -> A
// A   -> U
//
// >>> [ord(ch) for ch in ["G", "C", "T", "A"]]
// [71, 67, 84, 65]
char* to_rna(const char* dna) {
    size_t len = strlen(dna);
    char* rna = (char*)malloc(len + 1);
    if (rna == NULL) {
        fprintf(stderr, "ERROR: Could not allocation memory...\n");
        exit(1);
    }


    for (size_t i = 0; i < len; i++) {
        switch ((int)dna[i]) {
        case 71:
            rna[i] = 'C';
            break;
        case 67:
            rna[i] = 'G';
            break;
        case 84:
            rna[i] = 'A';
            break;
        case 65:
            rna[i] = 'U';
            break;
        default:
            fprintf(stderr, "ERROR: Invalid DNA - %s\n", dna);
            exit(1);
        }
    }

    rna[len] = '\0';
    return rna;
}
