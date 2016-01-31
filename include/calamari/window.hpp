//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_WINDOW_HPP
#define CALAMARI_WINDOW_HPP

#include "gl/gl.hpp"
#include "defines.hpp"
#include "error.hpp"

#include <string>

CALAMARI_NS

class Application;
class Renderer;
class EventManager;

class Window {
private:
    friend class Application;
    friend class Renderer;
    friend class EventManager;

    Window(EventManager& events, int w, int h, const char* title) throw(InitialisationError);
    ~Window();

    int should_close();
    void poll_events();

    GLFWwindow* window;

    void close(bool should = true);
};

CALAMARI_NS_END

#endif //CALAMARI_WINDOW_HPP
