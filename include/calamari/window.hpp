//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_WINDOW_HPP
#define CALAMARI_WINDOW_HPP

#include "calamari/defines.hpp"
#include "calamari/gl/gl_core_3_3.hpp"

#include <GLFW/glfw3.h>

#include <string>

CALAMARI_NS

class Application;
class Renderer;

class Window {
private:
    friend class Application;
    friend class Renderer;

    Window(Application& app, int w, int h, const char* title);
    ~Window();

    int should_close();
    void poll_events();

    GLFWwindow* window;

    void close();
};

CALAMARI_NS_END

#endif //CALAMARI_WINDOW_HPP
