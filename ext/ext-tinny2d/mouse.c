#include "tinny/mouse.h"

#include "SFML/Window/Mouse.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LENGTH_BUTTONS        102

static const char* buttons[LENGTH_BUTTONS] = {
        "left", "right", "middle", "xbutton1",
        "xbutton2", "count"
};

int find_key_button(const char *name) {
    int i;

    for (i = 0; i < LENGTH_BUTTONS; i++) {
        if (strcmp(buttons[i], name) == 0) {
            return i;
        }
    }

    return -1;
}

bool isButtonDown(const char *button) {
    int i = find_key_button(button);

    if(i < 0) {
        return false;
    }

    return sfMouse_isButtonPressed(i);
}