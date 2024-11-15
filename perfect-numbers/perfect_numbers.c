#include "perfect_numbers.h"

#include <math.h>

kind classify_number(int number) {
    if (number < 1)  return ERROR;
    if (number == 1) return DEFICIENT_NUMBER;

    int sum = 1;

    for (int i = 2; i <= (int)sqrt((float)number); i++) {
        if (number % i == 0) {
            sum += i;
            int compliment = number / i;
            if (compliment != i) {
                sum += compliment;
            }
        }
    }

    if (sum == number) {
        return PERFECT_NUMBER;
    }
    else if (sum > number) {
        return ABUNDANT_NUMBER;
    }
    else {
        return DEFICIENT_NUMBER;
    }

}
