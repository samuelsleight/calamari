//
// Created by Sam Sleight on 19/01/2016.
//

#ifndef CALAMARI_EVENTCALLBACKS_HPP
#define CALAMARI_EVENTCALLBACKS_HPP

#include "defines.hpp"

class GLFWwindow;

CALAMARI_NS

namespace callbacks {

void close_callback(GLFWwindow* window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

}

CALAMARI_NS_END

#endif //CALAMARI_EVENTCALLBACKS_HPP
