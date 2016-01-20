//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_RENDERER_HPP
#define CALAMARI_RENDERER_HPP

#include "defines.hpp"
#include "window.hpp"

namespace calamari {

class State;

class Renderer {
public:
    Renderer(Window& window);

    void render(State& state);

private:
    Window& window;
};

}


#endif //CALAMARI_RENDERER_HPP
