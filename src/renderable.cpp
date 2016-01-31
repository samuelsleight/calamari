//
// Created by Sam Sleight on 22/01/2016.
//

#include "calamari/renderable.hpp"
#include "calamari/state.hpp"

CALAMARI_NS

void Renderable::register_component(calamari::State& state) {
    state.register_renderable(*this);
}

size_t Renderable::get_index(float x, float y, float z) {
    for(size_t i = 0; i < vertices.size(); i += 3) {
        if(vertices[i] == x && vertices[i + 1] == y && vertices[i + 2] == z) {
            return i;
        }
    }

    size_t ret = vertices.size();
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
    return ret;
}

void Renderable::add_vertex(float x, float y, float z) {
    indices.push_back(get_index(x, y, z));
}

CALAMARI_NS_END
