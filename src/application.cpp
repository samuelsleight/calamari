//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/application.hpp"

CALAMARI_NS

Application::Application() throw(InitialisationError)
    : window(events, 800, 600, "Hello World"), renderer(window), events(*this) {}

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
