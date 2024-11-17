#include "robot_simulator.h"

#include <stdlib.h>
#include <string.h>

#define ROWS 4
#define COLS 2

const int directions[] = { 0, 1, 1, 0, 0, -1, -1, 0 };

robot_status_t robot_create(robot_direction_t direction, int x, int y) {
    robot_position_t position = {
        .x = x,
        .y = y
    };
    robot_status_t robot_status = {
        .direction = direction,
        .position = position
    };
    return robot_status;
}


int mod(int x, int y) {
    return ((x % y) + y) % y;
}

void robot_move(robot_status_t* robot, const char* commands) {
    if (robot == NULL || commands == NULL) {
        return;
    }

    int direction = (int)(robot->direction);
    robot_position_t position = robot->position;

    size_t length = strlen(commands);

    for (size_t i = 0; i < length; i++) {
        char command = commands[i];

        switch (command) {
        case 'R': {
            direction = mod(direction + 1, ROWS);
            break;
        }
        case 'A': {
            position.x += directions[direction * COLS];
            position.y += directions[direction * COLS + 1];
            break;
        }
        case 'L': {
            direction = mod(direction - 1, ROWS);
            break;
        }
        }
    }

    robot->direction = (robot_direction_t)direction;
    robot->position = position;
}