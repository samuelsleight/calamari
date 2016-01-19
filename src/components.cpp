//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/components.hpp"

#include <iostream>

CALAMARI_NS

void QuitHandler::register_object(calamari::State &state) {
    std::cout << "Quit handler registered" << std::endl;
    state.register_quit_handler(*this);
}

void KeyHandler::register_object(calamari::State& state) {
    std::cout << "Key handler registered" << std::endl;
    state.register_key_handler(*this);
}

CALAMARI_NS_END
