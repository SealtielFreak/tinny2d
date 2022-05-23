#include "tinny/events.h"

#include <stdlib.h>
#include <string.h>

#define LENGTH_EVENTS        24

static const char *events[LENGTH_EVENTS] = {
        "closed", "resized", "lost-focus", "gained-focus",
        "text-entered", "key-pressed", "key-released", "mouse-wheel-moved",
        "mousewheel-scrolled", "MouseButton-Pressed", "MouseButton-Released", "Mouse-Moved",
        "Mouse-Entered", "Mouse-Left", "JoystickButton-Pressed", "JoystickButton-Released",
        "Joystick-Moved", "Joystick-Connected", "Joystick-Disconnected", "Touch-Began",
        "TouchMoved", "TouchEnded", "SensorChanged", "count"
};

const char *getEventName(unsigned short name) {
    if (name < LENGTH_EVENTS) {
        return events[name];
    }

    return "";
}