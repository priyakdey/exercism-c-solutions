#include "gigasecond.h"

void gigasecond(time_t input, char* output, size_t size) {
    input = input + 1000000000;
    struct tm* ts = gmtime(&input);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", ts);
}