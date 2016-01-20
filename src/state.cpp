//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/state.hpp"
#include "calamari/components.hpp"
#include "calamari/camera.hpp"

CALAMARI_NS

void State::register_tick_handler(TickHandler& handler) {
    tick_handlers.push_back(handler);
}

void State::register_quit_handler(QuitHandler& handler) {
    quit_handlers.push_back(handler);
}

void State::register_key_handler(KeyHandler& handler) {
    key_handlers.push_back(handler);
}

void State::set_camera(Camera& camera) {
    this->camera = &camera;
}

void State::on_tick(Application& application) {
    for(TickHandler& handler : tick_handlers) {
        handler.on_tick(application);
    }
}

void State::on_quit(Application& application) {
    for(QuitHandler& handler : quit_handlers) {
        handler.on_quit(application);
    }
}

void State::on_key_press(Application& application, int key) {
    for(KeyHandler& handler : key_handlers) {
        handler.on_key_press(application, key);
    }
}

void State::on_key_release(Application& application, int key) {
    for(KeyHandler& handler : key_handlers) {
        handler.on_key_release(application, key);
    }
}

CALAMARI_NS_END
