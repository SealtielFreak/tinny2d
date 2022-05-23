#ifndef TINNY2D_TEXT_H
#define TINNY2D_TEXT_H

#include "tinny/structs.h"

typedef void *FontPointer;

typedef void *TextPointer;

typedef struct {
    FontPointer ptr_font;
    TextPointer ptr_text;
} Font;

Font createText(const char *filename);

void destroyText(Font *texture);

void print(Font font, const char *str);

#endif //TINNY2D_TEXT_H
