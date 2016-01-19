//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/window.hpp"
#include "calamari/application.hpp"
#include "calamari/eventcallbacks.hpp"

CALAMARI_NS

Window::Window(EventManager& events, int w, int h, const char* title) {
    if(!glfwInit()) {
        throw 5;
    }

    this->window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if(!this->window) {
        throw 5;
    }

    glfwMakeContextCurrent(this->window);
    glfwSetWindowUserPointer(this->window, &events);
    glfwSetWindowCloseCallback(this->window, callbacks::close_callback);
    glfwSetKeyCallback(this->window, callbacks::key_callback);

    if(!gl::sys::LoadFunctions()) {
        throw 5;
    }

    gl::Viewport(0, 0, w, h);
}

Window::~Window() {
    glfwDestroyWindow(this->window);
}

int Window::should_close() {
    return glfwWindowShouldClose(this->window);
}

void Window::poll_events() {
    glfwPollEvents();
}

void Window::close(bool should) {
    glfwSetWindowShouldClose(this->window, should);
}

CALAMARI_NS_END
