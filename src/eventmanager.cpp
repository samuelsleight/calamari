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
    application.state->on_key(application, key);
}

CALAMARI_NS_END
