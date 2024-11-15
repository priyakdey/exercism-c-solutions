#include "resistor_color_duo.h"

#include <stdlib.h>

uint16_t color_code(resistor_band_t resistor_bands[]) {
    uint16_t x = (uint16_t)resistor_bands[0];
    uint16_t y = (uint16_t)resistor_bands[1];
    return 10 * x + y;
}