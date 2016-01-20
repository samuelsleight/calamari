//
// Created by Sam Sleight on 19/01/2016.
//

#include "calamari/eventmanager.hpp"
#include "calamari/application.hpp"

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

CALAMARI_NS_END
