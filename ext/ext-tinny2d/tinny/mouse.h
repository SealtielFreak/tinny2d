#ifndef TINNY2D_MOUSE_H
#define TINNY2D_MOUSE_H

#include "tinny/structs.h"

#include <stdbool.h>

bool isButtonDown(const char *button);

void setMousePosition(float x, float y);

Vec2 getMousePosition();

#endif //TINNY2D_MOUSE_H
