#ifndef EXT_RB_TEXTURE_H
#define EXT_RB_TEXTURE_H

#include <ruby.h>

#include "tinny2d.h"

static Image* create_Image(const char *filename);

static void destroy_Image(void *ptr);

static VALUE rb_initImage(VALUE self, VALUE rb_filename);

static VALUE rb_newImage(VALUE self, VALUE rb_filename);

static VALUE rb_getImageSize(VALUE self);

static VALUE rb_getImageQuad(VALUE self);

#endif //EXT_RB_TEXTURE_H