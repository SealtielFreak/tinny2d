#include "tinny/text.h"

#include "SFML/Graphics/Font.h"
#include "SFML/Graphics/Text.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Font createText(const char *filename) {
    Font font;

    font.ptr_text = sfText_create();
    font.ptr_font = sfFont_createFromFile(filename);

    sfText_setFont(font.ptr_text, font.ptr_font);

    return font;
}

void destroyText(Font *texture) {

}

