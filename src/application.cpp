//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/application.hpp"

CALAMARI_NS

Application::Application() throw(InitialisationError)
    : window(events, 800, 600, "Hello World"), renderer(window), events(*this) {}

Vector<2, int> Application::get_window_size() {
    auto size = Vector<2, int>(0, 0);
    glfwGetFramebufferSize(window.window, &size.x, &size.y);
    return size;
};

void Application::run() {
    while (!window.should_close()) {
        state->on_tick(*this);

        renderer.render(*state);

        window.poll_events();
    }
}

void Application::quit() {
    window.close();
}

CALAMARI_NS_END
