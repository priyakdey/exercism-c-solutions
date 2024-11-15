#include "raindrops.h"

#define BUFFER_CAPACITY 1024

int add_raindrop(char buffer[], int start, int length, char* s) {
    int cursor = start;
    for (int i = 0; i < length; i++) {
        buffer[cursor] = s[i];
        cursor++;
    }

    return cursor;
}

void convert(char result[], int drops) {
    int cursor = 0;

    if (drops % 3 == 0) {
        cursor = add_raindrop(result, cursor, 5, "Pling");
    }
    if (drops % 5 == 0) {
        cursor = add_raindrop(result, cursor, 5, "Plang");
    }
    if (drops % 7 == 0) {
        cursor = add_raindrop(result, cursor, 5, "Plong");
    }
    if (cursor == 0) {
        char temp[BUFFER_CAPACITY] = { 0 };
        int temp_cursor = 0;
        while (drops > 0) {
            int rem = drops % 10;
            drops = drops / 10;
            temp[temp_cursor++] = (char)(rem + 48);
        }

        for (int i = temp_cursor - 1; i >= 0; i--) {
            result[cursor++] = temp[i];
        }
    }

}