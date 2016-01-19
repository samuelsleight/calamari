//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/components.hpp"

CALAMARI_NS

void QuitHandler::register_object(calamari::State &state) {
    state.register_quit_handler(*this);
}

CALAMARI_NS_END
