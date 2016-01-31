//
// Created by Sam Sleight on 31/01/2016.
//

#ifndef CALAMARI_KEY_HPP
#define CALAMARI_KEY_HPP

#include "gl/gl.hpp"
#include "defines.hpp"

CALAMARI_NS

#define EXPANDER(name, glfw) name = GLFW_KEY_##glfw,

enum class KeyCode {
    CALAMARI_KEY_X(EXPANDER)
};

#undef EXPANDER

KeyCode key_from_glfw(int key);

class Key {
public:
    Key(int key, int scancode);

    KeyCode key;
    int scancode;
};

CALAMARI_NS_END

#endif //CALAMARI_KEY_HPP
