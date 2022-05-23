#ifndef EXT_H
#define EXT_H

#include <ruby.h>

#include "tinny2d.h"

#include "ext/image.h"
#include "ext/text.h"
#include "ext/window.h"

VALUE rb_Vec2ToArr(Vec2 size);

VALUE rb_Quad2ToArr(Quad quad);

#endif //EXT_H