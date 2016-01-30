//
// Created by Sam Sleight on 18/01/2016.
//

#include <calamari/error.hpp>
#include "calamari/window.hpp"
#include "calamari/application.hpp"
#include "calamari/eventcallbacks.hpp"

CALAMARI_NS

namespace internal {

static std::string error_string;

void error_callback(int error, const char* description) {
    error_string = description;
}

}

Window::Window(EventManager& events, int w, int h, const char* title) throw(InitialisationError) {
    if(!glfwInit()) {
        throw InitialisationError("Error initialising GLFW");
    }

    glfwSetErrorCallback(internal::error_callback);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, gl::TRUE_);

    this->window = glfwCreateWindow(w, h, title, nullptr, nullptr);
    if(!this->window) {
        throw InitialisationError("Error creating window: " + internal::error_string);
    }

    glfwMakeContextCurrent(this->window);
    glfwSetWindowUserPointer(this->window, &events);
    glfwSetWindowCloseCallback(this->window, callbacks::close_callback);
    glfwSetKeyCallback(this->window, callbacks::key_callback);
    glfwSetFramebufferSizeCallback(this->window, callbacks::resize_callback);

    if(!gl::sys::LoadFunctions()) {
        throw InitialisationError("Error loading OpenGL functions");
    }
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
