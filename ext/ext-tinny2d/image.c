#include "tinny/image.h"

#include "SFML/Graphics.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


Image createImage(const char *filename) {
    Image texture;

    texture.ptr_texture = sfTexture_createFromFile(filename, NULL);
    texture.ptr_sprite = sfSprite_create();

    sfSprite_setTexture(texture.ptr_sprite, texture.ptr_texture, true);

    if (!texture.ptr_texture || !texture.ptr_sprite) {
        abort();
    }

    return texture;
}

void destroyImage(Image *texture) {
    sfTexture_destroy(texture->ptr_texture);
    sfSprite_destroy(texture->ptr_sprite);

    texture->ptr_texture = NULL;
    texture->ptr_texture = NULL;
}

Vec2 getImageSize(Image texture) {
    sfVector2u size_texture = sfTexture_getSize((sfTexture *) texture.ptr_texture);
    Vec2 size = {
            (float) size_texture.x,
            (float) size_texture.y
    };

    return size;
}

void setImageQuad(Image texture, Quad quad) {
    sfIntRect rect = { (int) quad.x, (int) quad.y, (int) quad.w, (int) quad.h };
    sfSprite_setTextureRect(texture.ptr_sprite, rect);
}

Quad getImageQuad(Image texture) {
    Vec2 size = getImageSize(texture);
    Quad quad = { 0, 0, (float) size.x, (float) size.y };

    return quad;
}