#include "dnd_character.h"

#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <sys/param.h>

#define MIN2(a, b)       MIN(a, b)
#define MIN3(a, b, c)    MIN2(MIN2(a, b), c)
#define MIN4(a, b, c, d) MIN3(MIN2(a, b), c, d)

int ability(void) {
    srand(time(NULL));
    int temp[4] = { 0 };
    for (int i = 0; i < 4; i++) {
        float n = (float)rand() / RAND_MAX;
        int number = ceil(n * 6);
        if (number == 0) {
            number += 1;
        }
        temp[i] = number;
    }

    int min = MIN4(temp[0], temp[1], temp[2], temp[3]);

    int points = 0;

    for (int i = 0; i < 4; i++) {
        if (min == temp[i]) {
            min = 0;    // reset to 0 to skip over duplicates
            continue;
        }
        points += temp[i];
    }

    return points;
}

int modifier(int score) {
    return floor((score - 10) / 2.0);
}

dnd_character_t make_dnd_character(void) {
    int strength = ability();
    int dexterity = ability();
    int constitution = ability();
    int intelligence = ability();
    int wisdom = ability();
    int charisma = ability();

    int hitpoints = modifier(constitution) + 10;
    dnd_character_t character = {
        .strength = strength,
        .dexterity = dexterity,
        .constitution = constitution,
        .intelligence = intelligence,
        .wisdom = wisdom,
        .charisma = charisma,
        .hitpoints = hitpoints
    };
    return character;
}