#ifndef TINNY2D_KEYBOARD_H
#define TINNY2D_KEYBOARD_H

#include <stdbool.h>


const char *getKeyName(unsigned short key);

bool isKeyDown(const char *name);

#endif //TINNY2D_KEYBOARD_H
