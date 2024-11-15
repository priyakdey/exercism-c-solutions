#include "resistor_color.h"

#include <stdio.h>
#include <stdlib.h>

int color_code(resistor_band_t resistor_color) {
    return (int)resistor_color;
}

resistor_band_t* colors() {
    resistor_band_t* colors = (resistor_band_t*)malloc(sizeof(resistor_band_t) * 10);
    if (colors == NULL) {
        fprintf(stderr, "could not allocate memory\n");
        exit(1);
    }

    for (size_t i = 0; i < 10; i++) {
        colors[i] = (resistor_band_t)i;
    }

    return colors;
}