//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/state.hpp"
#include "calamari/components.hpp"
#include "calamari/renderable.hpp"
#include "calamari/camera.hpp"

CALAMARI_NS

State::~State() {
    gl::DeleteBuffers(1, &vbo);

    for(Renderable& renderable : renderables) {
        gl::DeleteBuffers(1, &renderable.ebo);
    }
}

void State::register_tick_handler(TickHandler& handler) {
    tick_handlers.push_back(handler);
}

void State::register_quit_handler(QuitHandler& handler) {
    quit_handlers.push_back(handler);
}

void State::register_key_handler(KeyHandler& handler) {
    key_handlers.push_back(handler);
}

void State::register_resize_handler(ResizeHandler& handler) {
    resize_handlers.push_back(handler);
}

void State::register_renderable(Renderable& renderable) {
    renderables.push_back(renderable);
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

void State::on_resize(Application& application, Vector<2, int> size) {
    for(ResizeHandler& handler : resize_handlers) {
        handler.on_resize(application, size);
    }
}

CALAMARI_NS_END
