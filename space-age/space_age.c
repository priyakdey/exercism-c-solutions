#include "space_age.h"

#include <math.h>

const float planet_seconds[] = {
   0.24084670 * 31557600,
   0.61519726 * 31557600,
   1.00000000 * 31557600,
   1.88081580 * 31557600,
   11.8626150 * 31557600,
   29.4474980 * 31557600,
   84.0168460 * 31557600,
   164.791320 * 31557600
};

float age(planet_t planet, int64_t seconds) {
    int index = (int)planet;

    if (index < 0 || index >= 8 || seconds < 0) return -1;

    float planet_second = planet_seconds[index];
    return roundf((seconds / planet_second) * 100) / 100;
}