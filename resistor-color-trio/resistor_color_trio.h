#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

#define KB 0x3E8
#define MB 0xF4240
#define GB 0x3B9ACA00


typedef enum resistor_band {
    BLACK,
    BROWN,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    VIOLET,
    GREY,
    WHITE,
} resistor_band_t;

typedef  enum metric_unit {
    OHMS,
    KILOOHMS,
    MEGAOHMS,
    GIGAOHMS
} metric_unit_t;


typedef struct resistor_value {
    uint16_t value;
    metric_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t resistor_bands[]);

#endif
