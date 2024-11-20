#include "clock.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int proper_mod(int a, int b) {
    return ((a % b) + b) % b;
}

void parse_clock(clock_t clock, int* hour, int* minute) {
    char ch;
    int a, b;
    char* text = clock.text;

    ch = text[0];
    a = atoi(&ch);
    ch = text[1];
    b = atoi(&ch);
    *hour = 10 * a + b;

    ch = text[3];
    a = atoi(&ch);
    ch = text[4];
    b = atoi(&ch);
    *minute = 10 * a + b;
}

clock_t clock_create(int hour, int minute) {
    int rem = minute / 60;
    if (minute < 0) rem -= 1;
    minute = proper_mod(minute, 60);
    hour = proper_mod(hour + rem, 24);

    char text[MAX_STR_LEN] = { 0 };
    text[4] = (char)((minute % 10) + 48);
    text[3] = (char)(((minute / 10) % 10) + 48);
    text[2] = ':';
    text[1] = (char)((hour % 10) + 48);
    text[0] = (char)(((hour / 10) % 10) + 48);

    clock_t clock = { 0 };
    strncpy(clock.text, text, MAX_STR_LEN);

    return clock;
}


clock_t clock_add(clock_t clock, int minute_add) {
    int hour, minute;

    parse_clock(clock, &hour, &minute);

    minute += minute_add;

    int rem = minute / 60;
    if (minute < 0) rem -= 1;
    minute = proper_mod(minute, 60);
    hour = proper_mod(hour + rem, 24);

    char text[MAX_STR_LEN] = { 0 };
    text[4] = (char)((minute % 10) + 48);
    text[3] = (char)(((minute / 10) % 10) + 48);
    text[2] = ':';
    text[1] = (char)((hour % 10) + 48);
    text[0] = (char)(((hour / 10) % 10) + 48);

    printf("-- input clock = %s | minutes to add = %d | result = %s----\n", clock.text, minute_add, text);
    clock_t new_clock = { 0 };
    strncpy(new_clock.text, text, MAX_STR_LEN);

    return new_clock;
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    return clock_add(clock, -1 * minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    (void)a;
    (void)b;
    return false;
}