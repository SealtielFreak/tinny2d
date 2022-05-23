#ifndef EXT_RB_WINDOW_H
#define EXT_RB_WINDOW_H

#include <ruby.h>

#include "tinny2d.h"

static VALUE rb_configWindow(VALUE self, VALUE rb_antialiasing_level, VALUE rb_style);

static VALUE rb_createWindow(VALUE self, VALUE rb_width, VALUE rb_height, VALUE rb_title);

static VALUE rb_isAvailable(VALUE self);

static VALUE rb_setWindowTitle(VALUE self, VALUE rb_title);

static VALUE rb_getWindowTitle(VALUE self);

static VALUE rb_getDeltaTime(VALUE self);

static VALUE rb_resetTime(VALUE self);

static VALUE rb_getWindowSize(VALUE self);

static VALUE rb_getDisplayPosition(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_setDisplayPosition(VALUE self);

static VALUE rb_isRunning(VALUE self);

static VALUE rb_closeWindow(VALUE self);

static VALUE rb_destroy(VALUE self);

static VALUE rb_setFrameRate(VALUE self, VALUE rb_limit);

static VALUE rb_pollEvent(VALUE self);

static VALUE rb_waitEvent(VALUE self);

static VALUE rb_getNameEvent(VALUE self);

static VALUE rb_clearScreen(VALUE self);

static VALUE rb_updateScreen(VALUE self);

static VALUE rb_setViewPosition(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_getViewPosition(VALUE self);

static VALUE rb_setViewSize(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_getViewSize(VALUE self);

static VALUE rb_setViewAngle(VALUE self, VALUE rb_radius);

static VALUE rb_getViewAngle(VALUE self);

static VALUE rb_setViewCenter(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_getViewCenter(VALUE self);

static VALUE rb_drawTexture(VALUE self, VALUE rb_quad, VALUE rb_texture);

static VALUE rb_drawCircle(VALUE self, VALUE rb_radius);

static VALUE rb_drawRectangle(VALUE self, VALUE rb_width, VALUE rb_height);

static VALUE rb_drawPolygon(VALUE self, VALUE points);

static VALUE rb_setColor(VALUE self, VALUE rb_r, VALUE rb_g, VALUE rb_b, VALUE rb_a);

static VALUE rb_setPosition(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_setOrigin(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_setScale(VALUE self, VALUE rb_x, VALUE rb_y);

static VALUE rb_setAngle(VALUE self, VALUE rb_angle);

static VALUE rb_isKeyDown(VALUE self, VALUE rb_key);

#endif //EXT_RB_WINDOW_H