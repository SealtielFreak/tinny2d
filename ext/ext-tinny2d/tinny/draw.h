#ifndef TINNY2D_DRAW_H
#define TINNY2D_DRAW_H

#include "tinny/structs.h"
#include "tinny/image.h"

void drawImage(Quad quad, Image texture);

void drawCircle(float radius);

void drawRectangle(float width, float height);

void drawPolygon(float *points);

void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

void setPosition(float x, float y);

void setOrigin(float x, float y);

void setScale(float x, float y);

void setAngle(float angle);

#endif //TINNY2D_DRAW_H
