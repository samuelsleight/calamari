//
// Created by Sam Sleight on 19/01/2016.
//

#include "calamari/eventcallbacks.hpp"
#include "calamari/eventmanager.hpp"

#include <GLFW/glfw3.h>

CALAMARI_NS

namespace callbacks {

void close_callback(GLFWwindow* window) {
    EventManager* events = static_cast<EventManager*>(glfwGetWindowUserPointer(window));
    events->close_callback();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    EventManager* events = static_cast<EventManager*>(glfwGetWindowUserPointer(window));
    events->key_callback(key, scancode, action, mods);
}

}

CALAMARI_NS_END
