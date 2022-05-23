#ifndef TINNY2D_H
#define TINNY2D_H

#include "tinny/events.h"
#include "tinny/keyboard.h"
#include "tinny/draw.h"
#include "tinny/text.h"
#include "tinny/mouse.h"

#include <stdbool.h>

void configWindow(unsigned antialiasing_level, const char *style);

void createWindow(unsigned int width, unsigned int height, const char *title);

bool isAvailable(void);

void setWindowTitle(const char *title);

float getDeltaTime(void);

void resetTime(void);

void setWindowSize(float x, float y);

Vec2 getWindowSize(void);

void setWindowPosition(float x, float y);

Vec2 getWindowPosition(void);

bool isRunning(void);

void closeWindow(void);

void destroy(void);

void setFrameRate(unsigned int limit);

bool pollEvent(void);

bool waitEvent(void);

const char *getNameEvent(void);

void clearScreen(void);

void updateScreen(void);

void setViewPosition(float x, float y);

Vec2 getViewPosition(void);

void setViewSize(float x, float y);

Vec2 getViewSize(void);

void setViewRotate(float radius);

float getViewRotate(void);

void setViewCenter(float x, float y);

Vec2 getViewCenter();

#endif //TINNY2D_H
