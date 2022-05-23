#ifndef TINNY2D_IMAGE_H
#define TINNY2D_IMAGE_H

#include "tinny/structs.h"

typedef void *TexturePointer;

typedef void *SpritePointer;

typedef struct {
    TexturePointer ptr_texture;
    SpritePointer ptr_sprite;
} Image;

Image createImage(const char *filename);

void destroyImage(Image *texture);

Vec2 getImageSize(Image texture);

void setImageQuad(Image texture, Quad quad);

Quad getImageQuad(Image texture);

#endif //TINNY2D_IMAGE_H
