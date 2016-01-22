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
    Renderer(Window& window) throw(InitialisationError);

    void load_scene(State& state);
    void render(State& state);

private:
    GLint shader_program;

    Window& window;
};

}


#endif //CALAMARI_RENDERER_HPP
