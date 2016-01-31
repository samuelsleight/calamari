//
// Created by Sam Sleight on 31/01/2016.
//

#include "calamari/key.hpp"

CALAMARI_NS

#define EXPANDER(name, glfw) case GLFW_KEY_##glfw: return KeyCode::name;

KeyCode key_from_glfw(int key) {
    switch(key) {
        CALAMARI_KEY_X(EXPANDER)

        default:
            return KeyCode::Other;
    }
}

Key::Key(int key, int scancode)
    : key(key_from_glfw(key)), scancode(scancode) {}

#undef EXPANDER

CALAMARI_NS_END
