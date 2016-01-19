//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/state.hpp"
#include "calamari/components.hpp"

CALAMARI_NS


void State::register_quit_handler(QuitHandler& handler) {
    quit_handlers.push_back(handler);
}

void State::on_quit(Application& application) {
    for(QuitHandler& handler : quit_handlers) {
        handler.on_quit(application);
    }
}

CALAMARI_NS_END
