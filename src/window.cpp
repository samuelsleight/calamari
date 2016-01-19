//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/window.hpp"
#include "calamari/application.hpp"

CALAMARI_NS

namespace callbacks {

void close_callback(GLFWwindow* window) {
    glfwSetWindowShouldClose(window, false);
    Application* app = static_cast<Application*>(glfwGetWindowUserPointer(window));
    app->close_callback();
}

}

Window::Window(Application& app, int w, int h, const char* title) {
    if(!glfwInit()) {
        throw 5;
    }

    this->window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if(!this->window) {
        throw 5;
    }

    glfwMakeContextCurrent(this->window);
    glfwSetWindowUserPointer(this->window, &app);
    glfwSetWindowCloseCallback(this->window, callbacks::close_callback);

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

void Window::close() {
    glfwSetWindowShouldClose(this->window, true);
}

CALAMARI_NS_END
