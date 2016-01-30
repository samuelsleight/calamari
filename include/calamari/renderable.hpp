//
// Created by Sam Sleight on 22/01/2016.
//

#ifndef CALAMARI_RENDERABLE_HPP
#define CALAMARI_RENDERABLE_HPP

#include "defines.hpp"
#include "gl/gl_core_3_3.hpp"

#include <vector>

CALAMARI_NS

class State;
class Renderer;

class Renderable {
public:
    virtual void register_component(calamari::State& state);

    void add_vertex(float x, float y, float z);

private:
    friend class Renderer;

    GLuint vbo;
    std::vector<float> vertices;
};

CALAMARI_NS_END

#endif //CALAMARI_RENDERABLE_HPP
