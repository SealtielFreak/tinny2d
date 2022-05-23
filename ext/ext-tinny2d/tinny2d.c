#include "tinny2d.h"
#include "tinny/resources/icon.h"

#include "SFML/Graphics.h"
#include "SFML/Window.h"
#include "SFML/System.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static sfRenderWindow *m_window = NULL;
static sfClock *m_clock = NULL;
static sfView *m_view = NULL;

static sfWindowStyle m_style = sfDefaultStyle;
static sfEvent m_event;
static sfColor m_color;
static sfContextSettings m_context;

static sfCircleShape *m_circle = NULL;
static sfRectangleShape *m_rectangle = NULL;
static sfConvexShape *m_polygon = NULL;

static sfVector2f m_position = {0, 0};
static sfVector2f m_origin = {0, 0};
static sfVector2f m_scale = {1, 1};
static float m_angle = 0;

static sfImage *m_icon;
static sfVector2f m_view_position = { 0, 0 };


sfVector2f setVec2f(float x, float y) {
    sfVector2f vec = {x, y};
    return vec;
}

sfVector2i setVec2i(int x, int y) {
    sfVector2i vec = {x, y};
    return vec;
}

sfVector2u setVec2u(unsigned x, unsigned y) {
    sfVector2u vec = {x, y};
    return vec;
}

sfIntRect castIntQuad(Quad quad) {
    sfIntRect rect = { (int) quad.x, (int) quad.y, (int) quad.w, (int) quad.h };
    return rect;
}

void configWindow(unsigned antialiasing_level, const char *style) {
    m_context.antialiasingLevel = antialiasing_level;

    if(style == NULL) {
        return;
    }

    if(strcmp(style, "default") == 0) {
        m_style = sfDefaultStyle;
    } else if(strcmp(style, "closed") == 0) {
        m_style = sfClose;
    } else if(strcmp(style, "fullscreen") == 0) {
        m_style = sfFullscreen;
    } else {
        fprintf(stderr, "Style no found");
    }
}

void createWindow(unsigned int width, unsigned int height, const char *title) {
    sfVideoMode mode = {width, height, 32};
    m_window = sfRenderWindow_create(mode, title, m_style, &m_context);
    m_clock = sfClock_create();
    m_view = (sfView*) sfRenderWindow_getView(m_window);
    m_icon = sfImage_createFromMemory(icon_emmbedData, sizeof(icon_emmbedData) / sizeof(icon_emmbedData[0]));

    if(!sfVideoMode_isValid(mode)) {
        fprintf(stderr, "Invalid config");
        abort();
    }

    if (!isAvailable()) {
        return;
    }

    sfRenderWindow_setIcon(m_window, ICON_W, ICON_H, sfImage_getPixelsPtr(m_icon));

    m_circle = sfCircleShape_create();
    m_rectangle = sfRectangleShape_create();
    m_polygon = sfConvexShape_create();
}

bool isAvailable(void) {
    return m_window != NULL;
}

void setWindowTitle(const char *title) {
    sfRenderWindow_setTitle(m_window, title);
}

float getDeltaTime(void) {
    return sfTime_asSeconds(sfClock_getElapsedTime(m_clock));
}

void resetTime(void) {
    sfClock_restart(m_clock);
}

void setWindowSize(float x, float y) {
    sfRenderWindow_setSize(m_window, setVec2u((unsigned int) x, (unsigned int) y));
}

Vec2 getWindowSize(void) {
    sfVector2u size_window = sfRenderWindow_getSize(m_window);
    Vec2 size = {(float) size_window.x, (float) size_window.y};

    return size;
}

void setWindowPosition(float x, float y) {
    sfRenderWindow_setSize(m_window, setVec2u((unsigned) x, (unsigned) y));
}

Vec2 getWindowPosition(void) {
    sfVector2i position_window = sfRenderWindow_getPosition(m_window);
    Vec2 position = {(float) position_window.x, (float) position_window.y};

    return position;
}

bool isRunning(void) {
    if (m_window == NULL) {
        return false;
    }

    return sfRenderWindow_isOpen(m_window);
}

void closeWindow(void) {
    sfRenderWindow_close(m_window);
}

void destroy(void) {
    sfRenderWindow_destroy(m_window);

    sfCircleShape_destroy(m_circle);
    sfRectangleShape_destroy(m_rectangle);
    sfConvexShape_destroy(m_polygon);
    sfImage_destroy(m_icon);

    m_window = NULL;
}

void setFrameRate(unsigned int limit) {
    sfRenderWindow_setFramerateLimit(m_window, limit);
}

bool pollEvent(void) {
    return sfRenderWindow_pollEvent(m_window, &m_event);
}

bool waitEvent(void) {
    return sfRenderWindow_waitEvent(m_window, &m_event);
}

const char *getNameEvent(void) {
    return getEventName(m_event.type);
}

void clearScreen(void) {
    sfRenderWindow_clear(m_window, m_color);
}

void updateScreen(void) {
    sfRenderWindow_display(m_window);

    m_color = sfBlack;
    m_position = setVec2f(0, 0);
    m_origin = setVec2f(0, 0);
    m_scale = setVec2f(1, 1);
}

void setViewPosition(float x, float y) {
    m_view_position.x += x;
    m_view_position.y += y;

    sfView_move(m_view, m_view_position);
    sfRenderWindow_setView(m_window, m_view);
}

Vec2 getViewPosition(void) {
    Vec2 position = {
            m_view_position.x, m_view_position.y
    };

    return position;
}

void setViewSize(float x, float y) {
    sfView_setSize(m_view, setVec2f(x, y));
    sfRenderWindow_setView(m_window, m_view);
}

Vec2 getViewSize(void) {
    sfVector2f size_view = sfView_getSize(m_view);
    Vec2 size = { size_view.x, size_view.y };

    return size;
}

void setViewRotate(float radius) {
    sfView_setRotation(m_view, radius);
    sfRenderWindow_setView(m_window, m_view);
}

float getViewRotate(void) {
    return sfView_getRotation(m_view);
}

void setMousePosition(float x, float y) {
    sfMouse_setPositionRenderWindow(setVec2i((int) x, (int) y), m_window);
}

Vec2 getMousePosition() {
    sfVector2i position_mouse = sfMouse_getPositionRenderWindow(m_window);
    Vec2 position = { (float) position_mouse.x, (float) position_mouse.y };

    return position;
}

void setViewCenter(float x, float y) {
    sfView_setCenter(m_view, setVec2f(x, y));
    sfRenderWindow_setView(m_window, m_view);
}

void drawImage(Quad quad, Image texture) {
    if (!texture.ptr_texture || !texture.ptr_sprite) {
        return;
    }

    sfSprite_setOrigin(texture.ptr_sprite, m_origin);
    sfSprite_setPosition(texture.ptr_sprite, m_position);
    sfSprite_setRotation(texture.ptr_sprite, m_angle);
    sfSprite_setScale(texture.ptr_sprite, m_scale);

    sfRenderWindow_drawSprite(m_window, texture.ptr_sprite, NULL);
}

void drawCircle(float radius) {
    sfCircleShape_setOrigin(m_circle, m_origin);
    sfCircleShape_setPosition(m_circle, m_position);
    sfCircleShape_setRadius(m_circle, radius);
    sfCircleShape_setScale(m_circle, m_scale);
    sfCircleShape_setRotation(m_circle, m_angle);
    sfCircleShape_setFillColor(m_circle, m_color);

    sfRenderWindow_drawCircleShape(m_window, m_circle, NULL);
}

void drawRectangle(float width, float height) {
    sfVector2f size = setVec2f(width, height);

    sfRectangleShape_setOrigin(m_rectangle, m_origin);
    sfRectangleShape_setPosition(m_rectangle, m_position);
    sfRectangleShape_setSize(m_rectangle, size);
    sfRectangleShape_setScale(m_rectangle, m_scale);
    sfRectangleShape_setRotation(m_rectangle, m_angle);
    sfRectangleShape_setFillColor(m_rectangle, m_color);

    sfRenderWindow_drawRectangleShape(m_window, m_rectangle, NULL);
}

void drawPolygon(float *points) {

}

void print(Font font, const char *str) {
    sfText_setOrigin(font.ptr_text, m_origin);
    sfText_setPosition(font.ptr_text, m_position);
    sfText_setScale(font.ptr_text, m_scale);
    sfText_setRotation(font.ptr_text, m_angle);
    sfText_setFillColor(font.ptr_text, m_color);

    sfText_setString(font.ptr_text, str);

    sfRenderWindow_drawText(m_window, font.ptr_text, NULL);
}

void setColor(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    sfColor background = {r, g, b, a};
    m_color = background;
}

void setPosition(float x, float y) {
    m_position = setVec2f(x, y);
}

void setOrigin(float x, float y) {
    m_origin = setVec2f(x, y);
}

void setScale(float x, float y) {
    m_scale = setVec2f(x, y);
}

void setAngle(float angle) {
    m_angle = angle;
}