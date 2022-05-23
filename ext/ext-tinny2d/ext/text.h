#ifndef EXT_RB_TEXT_H
#define EXT_RB_TEXT_H

#include <ruby.h>

#include "tinny2d.h"

static Font* create_Text(const char *filename);

static void destroy_Text(void *ptr);

static VALUE rb_initText(VALUE self, VALUE rb_filename);

static VALUE rb_newText(VALUE self, VALUE rb_filename);

static VALUE rb_print(VALUE self, VALUE rb_font, VALUE rb_str);

#endif //EXT_RB_TEXT_H
