//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/components.hpp"

#include <iostream>

CALAMARI_NS

void TickHandler::register_component(State& state) {
    state.register_tick_handler(*this);
}

void QuitHandler::register_component(State &state) {
    state.register_quit_handler(*this);
}

void KeyHandler::register_component(State& state) {
    state.register_key_handler(*this);
}

void ResizeHandler::register_component(State& state) {
    state.register_resize_handler(*this);
}

CALAMARI_NS_END
