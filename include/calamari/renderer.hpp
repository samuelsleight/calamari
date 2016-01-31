//
// Created by Sam Sleight on 18/01/2016.
//

#ifndef CALAMARI_RENDERER_HPP
#define CALAMARI_RENDERER_HPP

#include "gl/gl.hpp"
#include "defines.hpp"
#include "window.hpp"

CALAMARI_NS

namespace impl {

GLuint create_shader(GLenum shader_type, const GLchar** shader_source, const char* error_message);

}

class State;

class Renderer {
public:
    Renderer(Window& window) throw(InitialisationError);

    void load_scene(State& state);
    void render(State& state);

private:
    GLuint shader_program;

    Window& window;
};

CALAMARI_NS_END

#endif //CALAMARI_RENDERER_HPP
