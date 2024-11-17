#include "resistor_color_trio.h"

#include <math.h>
#include <stdio.h>

resistor_value_t color_code(resistor_band_t resistor_bands[])
{
    int first_digit = (int)resistor_bands[0];
    int second_digit = (int)resistor_bands[1];
    int zeroes = (int)resistor_bands[2];

    uint16_t value = 10 * first_digit + second_digit;
    metric_unit_t unit = OHMS;

    if (value % 10 == 0) {
        zeroes += 1;
        value = value / 10;
    }


    if (zeroes < 3) {
        value = value * (int)pow(10, zeroes);
        unit = OHMS;
    }
    else if (zeroes < 6) {
        value = value * (int)pow(10, zeroes - 3);
        unit = KILOOHMS;
    }
    else if (zeroes < 9) {
        value = value * (int)pow(10, zeroes - 6);
        unit = MEGAOHMS;
    }
    else {
        value = value * (int)pow(10, zeroes - 9);
        unit = GIGAOHMS;
    }

    resistor_value_t resistor = {
        .value = (uint16_t)value,
        .unit = unit
    };

    return resistor;
}
