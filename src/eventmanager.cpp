//
// Created by Sam Sleight on 19/01/2016.
//

#include "calamari/eventmanager.hpp"
#include "calamari/application.hpp"
#include "calamari/vector.hpp"

CALAMARI_NS

EventManager::EventManager(Application& application) : application(application) {}

void EventManager::close_callback() {
    application.window.close(false);
    application.state->on_quit(application);
}

void EventManager::key_callback(int key, int scancode, int action, int mods) {
    switch(action) {
        case GLFW_PRESS:
            application.state->on_key_press(application, key);
            break;

        case GLFW_RELEASE:
            application.state->on_key_release(application, key);
            break;

        default:
            break;
    }
}

void EventManager::resize_callback(int width, int height) {
    application.state->on_resize(application, Vector<2, int>(width, height));
}

CALAMARI_NS_END
