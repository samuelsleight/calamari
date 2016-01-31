//
// Created by Sam Sleight on 22/01/2016.
//

#ifndef CALAMARI_RENDERABLE_HPP
#define CALAMARI_RENDERABLE_HPP

#include "gl/gl_core_3_3.hpp"
#include "defines.hpp"
#include "transformable.hpp"

#include <vector>

CALAMARI_NS

class State;
class Renderer;

class Renderable : public Transformable {
public:
    virtual void register_component(calamari::State& state);

    void add_vertex(float x, float y, float z);

private:
    friend class State;
    friend class Renderer;

    size_t get_index(float x, float y, float z);

    GLuint vbo, ebo;
    std::vector<float> vertices;
    std::vector<size_t> indices;
};

CALAMARI_NS_END

#endif //CALAMARI_RENDERABLE_HPP
