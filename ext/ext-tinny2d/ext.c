#include "ext.h"

#include <stdio.h>
#include <stdlib.h>

static VALUE rb_mExt, rb_cImage, rb_cFont;

void Init_ext(void) {
    rb_mExt = rb_define_module("Ext");

    VALUE rb_mWindow = rb_define_module_under(rb_mExt, "Window");

    rb_define_module_function(rb_mWindow, "config", rb_configWindow, 2);
    rb_define_module_function(rb_mWindow, "init", rb_createWindow, 3);
    rb_define_module_function(rb_mWindow, "is_available?", rb_isAvailable, 0);
    rb_define_module_function(rb_mWindow, "set_title", rb_setWindowTitle, 1);
    rb_define_module_function(rb_mWindow, "get_title", rb_getWindowTitle, 0);
    rb_define_module_function(rb_mWindow, "delta_time", rb_getDeltaTime, 0);
    rb_define_module_function(rb_mWindow, "reset_time!", rb_resetTime, 0);
    rb_define_module_function(rb_mWindow, "get_size", rb_getWindowSize, 0);
    rb_define_module_function(rb_mWindow, "set_position", rb_getDisplayPosition, 2);
    rb_define_module_function(rb_mWindow, "get_postion", rb_setDisplayPosition, 0);
    rb_define_module_function(rb_mWindow, "is_running?", rb_isRunning, 0);
    rb_define_module_function(rb_mWindow, "close", rb_closeWindow, 0);
    rb_define_module_function(rb_mWindow, "destroy", rb_destroy, 0);
    rb_define_module_function(rb_mWindow, "set_frame_rate", rb_setFrameRate, 1);
    rb_define_module_function(rb_mWindow, "clear", rb_clearScreen, 0);
    rb_define_module_function(rb_mWindow, "update", rb_updateScreen, 0);

    VALUE rb_mView = rb_define_module_under(rb_mWindow, "View");
    
    rb_define_module_function(rb_mView, "set_position", rb_setViewPosition, 2);
    rb_define_module_function(rb_mView, "get_position", rb_getViewPosition, 0);
    rb_define_module_function(rb_mView, "set_size", rb_setViewSize, 2);
    rb_define_module_function(rb_mView, "get_size", rb_getViewSize, 0);
    rb_define_module_function(rb_mView, "set_angle", rb_setViewAngle, 1);
    rb_define_module_function(rb_mView, "get_angle", rb_getViewAngle, 1);
    rb_define_module_function(rb_mView, "set_center", rb_setViewCenter, 2);
    rb_define_module_function(rb_mView, "get_center", rb_getViewCenter, 0);

    VALUE rb_mEvent = rb_define_module_under(rb_mExt, "Event");

    rb_define_module_function(rb_mEvent, "poll?", rb_pollEvent, 0);
    rb_define_module_function(rb_mEvent, "wait?", rb_waitEvent, 0);
    rb_define_module_function(rb_mEvent, "name", rb_getNameEvent, 0);

    VALUE rb_mDraw = rb_define_module_under(rb_mExt, "Draw");
    
    rb_define_module_function(rb_mDraw, "print", rb_print, 2);
    rb_define_module_function(rb_mDraw, "texture", rb_drawTexture, 2);
    rb_define_module_function(rb_mDraw, "circle", rb_drawCircle, 1);
    rb_define_module_function(rb_mDraw, "rectangle", rb_drawRectangle, 2);
    rb_define_module_function(rb_mDraw, "polygon", rb_drawPolygon, 1);
    rb_define_module_function(rb_mDraw, "color", rb_setColor, 4);
    rb_define_module_function(rb_mDraw, "position", rb_setPosition, 2);
    rb_define_module_function(rb_mDraw, "origin", rb_setOrigin, 2);
    rb_define_module_function(rb_mDraw, "scale", rb_setScale, 2);
    rb_define_module_function(rb_mDraw, "angle", rb_setAngle, 1);

    rb_cImage = rb_define_class_under(rb_mDraw, "Image", rb_cObject);

    rb_define_singleton_method(rb_cImage, "new", rb_newImage, 1);
    rb_define_method(rb_cImage, "initialize", rb_initImage, 1);
    rb_define_method(rb_cImage, "size", rb_getImageSize, 0);
    rb_define_method(rb_cImage, "quad", rb_getImageQuad, 0);

    rb_cFont = rb_define_class_under(rb_mDraw, "Font", rb_cObject);
    rb_define_singleton_method(rb_cFont, "new", rb_newText, 1);
    rb_define_method(rb_cFont, "initialize", rb_initText, 1);

    VALUE rb_mKeyboard = rb_define_module_under(rb_mExt, "Keyboard");

    rb_define_module_function(rb_mKeyboard, "is_key_down?", rb_isKeyDown, 1);

    VALUE rb_mMouse = rb_define_module_under(rb_mExt, "Mouse");
}

VALUE rb_Quad2ToArr(Quad quad) {
    VALUE rb_arr = rb_ary_new();
    
    rb_ary_push(rb_arr, INT2NUM(quad.x));
    rb_ary_push(rb_arr, INT2NUM(quad.y));
    rb_ary_push(rb_arr, INT2NUM(quad.w));
    rb_ary_push(rb_arr, INT2NUM(quad.h));

    return rb_arr;
}

VALUE rb_Vec2ToArr(Vec2 size) {
    VALUE rb_arr = rb_ary_new();
    
    rb_ary_push(rb_arr, INT2NUM(size.x));
    rb_ary_push(rb_arr, INT2NUM(size.y));

    return rb_arr;
}

/* Window module */
static VALUE rb_configWindow(VALUE self, VALUE rb_antialiasing_level, VALUE rb_style) {
    Check_Type(rb_antialiasing_level, T_FIXNUM);
    Check_Type(rb_style, T_STRING);

    configWindow(NUM2INT(rb_antialiasing_level), RSTRING_PTR(rb_style));
}

static VALUE rb_createWindow(VALUE self, VALUE rb_width, VALUE rb_height, VALUE rb_title) {
    Check_Type(rb_width, T_FIXNUM);
    Check_Type(rb_height, T_FIXNUM);
    Check_Type(rb_title, T_STRING);

    createWindow(NUM2INT(rb_width), NUM2INT(rb_height), RSTRING_PTR(rb_title));

    return Qnil;
}

static VALUE rb_isAvailable(VALUE self) {
    if(isAvailable()) {
        return Qtrue;
    }

    return Qfalse;
}

static VALUE rb_setWindowTitle(VALUE self, VALUE rb_title) {
    Check_Type(rb_title, T_STRING);
    
    setWindowTitle(RSTRING_PTR(rb_title));

    return Qnil;
}

static VALUE rb_getWindowTitle(VALUE self) {
    return Qnil;
}

static VALUE rb_getDeltaTime(VALUE self) {
    return DBL2NUM(getDeltaTime());
}

static VALUE rb_resetTime(VALUE self) {
    resetTime();
    return Qnil;
}

static VALUE rb_getWindowSize(VALUE self) {
    return rb_Vec2ToArr(getWindowSize());
}

static VALUE rb_getDisplayPosition(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FIXNUM);
    Check_Type(rb_y, T_FIXNUM);

    setWindowPosition(NUM2INT(rb_x), NUM2INT(rb_y));

    return Qnil;
}

static VALUE rb_setDisplayPosition(VALUE self) {
    return rb_Vec2ToArr(getWindowPosition());
}

static VALUE rb_isRunning(VALUE self) {
    if(isRunning()) {
        return Qtrue;
    }
    
    return Qfalse;
}

static VALUE rb_closeWindow(VALUE self) {
    closeWindow();
    return Qnil;
}

static VALUE rb_destroy(VALUE self) {
    destroy();
    return Qnil;
}

static VALUE rb_setFrameRate(VALUE self, VALUE rb_limit) {
    Check_Type(rb_limit, T_FIXNUM);

    setFrameRate(UINT2NUM(rb_limit));

    return Qnil;
}

static VALUE rb_pollEvent(VALUE self) {
    if(pollEvent()) {
        return Qtrue;
    }

    return Qfalse;
}

static VALUE rb_waitEvent(VALUE self) {
    if(waitEvent()) {
        return Qtrue;
    }

    return Qfalse;
}

static VALUE rb_getNameEvent(VALUE self) {
    return rb_str_new2(getNameEvent());
}

static VALUE rb_clearScreen(VALUE self) {
    clearScreen();

    return Qnil;
}

static VALUE rb_updateScreen(VALUE self) {
    updateScreen();

    return Qnil;
}

static VALUE rb_setViewPosition(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FIXNUM);
    Check_Type(rb_y, T_FIXNUM);

    setViewPosition(NUM2DBL(rb_x), NUM2DBL(rb_y));

    return Qnil;
}

static VALUE rb_getViewPosition(VALUE self) {
    return rb_Vec2ToArr(getViewPosition());;
}

static VALUE rb_setViewSize(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FIXNUM);
    Check_Type(rb_y, T_FIXNUM);

    setViewSize(NUM2DBL(rb_x), NUM2DBL(rb_y));
    return Qnil;
}

static VALUE rb_getViewSize(VALUE self) {
    return rb_Vec2ToArr(getViewSize());
}

static VALUE rb_setViewAngle(VALUE self, VALUE rb_radius) {
    Check_Type(rb_radius, T_FIXNUM);
    setViewRotate(NUM2DBL(rb_radius));
    return Qnil;
}

static VALUE rb_getViewAngle(VALUE self) {
    return DBL2NUM(getViewRotate());
}

static VALUE rb_setViewCenter(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FIXNUM);
    Check_Type(rb_y, T_FIXNUM);

    setViewCenter(NUM2DBL(rb_x), NUM2DBL(rb_y));
    return Qnil;
}

static VALUE rb_getViewCenter(VALUE self) {
    return Qnil;
}

static VALUE rb_drawTexture(VALUE self, VALUE rb_quad, VALUE rb_image) {
    Image *m_image;
    Data_Get_Struct(rb_image, Image, m_image);

    Quad m_quad = {
        NUM2INT(rb_ary_entry(rb_quad, 0)),
        NUM2INT(rb_ary_entry(rb_quad, 1)),
        NUM2INT(rb_ary_entry(rb_quad, 2)),
        NUM2INT(rb_ary_entry(rb_quad, 3)),
    };

    drawImage(m_quad, *m_image);
    
    return Qnil;
}

static VALUE rb_drawCircle(VALUE self, VALUE rb_radius) {
    Check_Type(rb_radius, T_FLOAT);

    drawCircle((float) NUM2DBL(rb_radius));
    
    return Qnil;
}

static VALUE rb_drawRectangle(VALUE self, VALUE rb_width, VALUE rb_height) {
    Check_Type(rb_width, T_FLOAT);
    Check_Type(rb_height, T_FLOAT);

    drawRectangle((float) NUM2DBL(rb_width), (float) NUM2DBL(rb_height));
    

    return Qnil;
}

static VALUE rb_drawPolygon(VALUE self, VALUE points) {
    return Qnil;
}


static VALUE rb_setColor(VALUE self, VALUE rb_r, VALUE rb_g, VALUE rb_b, VALUE rb_a) {
    Check_Type(rb_r, T_FIXNUM);
    Check_Type(rb_g, T_FIXNUM);
    Check_Type(rb_b, T_FIXNUM);
    Check_Type(rb_a, T_FIXNUM);

    setColor(UINT2NUM(rb_r), UINT2NUM(rb_g), UINT2NUM(rb_b), UINT2NUM(rb_a));

    return Qnil;
}

static VALUE rb_setPosition(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FLOAT);
    Check_Type(rb_y, T_FLOAT);

    setPosition((float) NUM2DBL(rb_x), (float) NUM2DBL(rb_y));
    return Qnil;
}

static VALUE rb_setOrigin(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FLOAT);
    Check_Type(rb_y, T_FLOAT);

    setOrigin((float) NUM2DBL(rb_x), (float) NUM2DBL(rb_y));
    return Qnil;
}

static VALUE rb_setScale(VALUE self, VALUE rb_x, VALUE rb_y) {
    Check_Type(rb_x, T_FLOAT);
    Check_Type(rb_y, T_FLOAT);

    setScale((float) NUM2DBL(rb_x), (float) NUM2DBL(rb_y));
    return Qnil;
}

static VALUE rb_setAngle(VALUE self, VALUE rb_angle) {
    Check_Type(rb_angle, T_FLOAT);

    setAngle((float) NUM2DBL(rb_angle));
    return Qnil;
}

static VALUE rb_isKeyDown(VALUE self, VALUE rb_key) {
    Check_Type(rb_key, T_STRING);

    if(isKeyDown(RSTRING_PTR(rb_key))) {
        return Qtrue;
    }

    return Qfalse;
}

/* Image Class */
static Image* create_Image(const char *filename) {
    Image *ptr_image;
    Image m_image = createImage(filename);
    
    ptr_image = malloc(sizeof(Image));

    ptr_image->ptr_sprite = m_image.ptr_sprite;
    ptr_image->ptr_texture = m_image.ptr_texture;

    return ptr_image;
}

static void destroy_Image(void *ptr) {
    destroyImage(ptr);
    free(ptr);
}

static VALUE rb_initImage(VALUE self, VALUE rb_filename) {
    rb_iv_set(self, "@filename", rb_filename);

    return self;
}

static VALUE rb_newImage(VALUE self, VALUE rb_filename) {
    Check_Type(rb_filename, T_STRING);
    VALUE argv[1] = { rb_filename };
    

    Image *m_image = create_Image(RSTRING_PTR(rb_filename));
    VALUE rb_image = Data_Wrap_Struct(self, 0, destroy_Image, m_image);

    rb_obj_call_init(rb_image, 1, argv);

    return rb_image;
}

static VALUE rb_getImageSize(VALUE self) {
    Image *m_image;
    Data_Get_Struct(self, Image, m_image);

    return rb_Vec2ToArr(getImageSize(*m_image));
}

static VALUE rb_getImageQuad(VALUE self) {
    Image *m_image;
    Data_Get_Struct(self, Image, m_image);

    return rb_Quad2ToArr(getImageQuad(*m_image));
}

/* Font Class */
static Font* create_Text(const char *filename) {
    Font *ptr_font;
    Font m_font = createText(filename);

    ptr_font = malloc(sizeof(Font));
    
    ptr_font->ptr_font = m_font.ptr_font;
    ptr_font->ptr_text = m_font.ptr_text;

    return ptr_font;
}

static void destroy_Text(void *ptr) {
    destroyText(ptr);

    free(ptr);
}

static VALUE rb_initText(VALUE self, VALUE rb_filename) {
    rb_iv_set(self, "@filename", rb_filename);

    return self;
}

static VALUE rb_newText(VALUE self, VALUE rb_filename) {
    Check_Type(rb_filename, T_STRING);
    VALUE argv[1] = { rb_filename };
    

    Font *m_font = create_Text(RSTRING_PTR(rb_filename));
    VALUE rb_font = Data_Wrap_Struct(self, 0, destroy_Text, m_font);

    rb_obj_call_init(rb_font, 1, argv);

    return rb_font;
}

static VALUE rb_print(VALUE self, VALUE font, VALUE str)  {
    Font *m_font;
    Data_Get_Struct(font, Font, m_font);

    print(*m_font, RSTRING_PTR(str));
    
    return Qnil;
}