#include "darts.h"

#include <math.h>

uint8_t score(coordinate_t position) {
    float distance = sqrtf(powf(position.x, 2.0) + powf(position.y, 2.0f));
    if (distance <= 1.0f) {
        return 10;
    }
    else if (distance <= 5.0) {
        return 5;
    }
    else if (distance <= 10.0) {
        return 1;
    }
    else {
        return 0;
    }
}
