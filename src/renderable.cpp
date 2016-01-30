//
// Created by Sam Sleight on 22/01/2016.
//

#include "calamari/renderable.hpp"
#include "calamari/state.hpp"

CALAMARI_NS

void Renderable::register_component(calamari::State& state) {
    state.register_renderable(*this);
}

void Renderable::add_vertex(float x, float y, float z) {
    vertices.push_back(x);
    vertices.push_back(y);
    vertices.push_back(z);
}

CALAMARI_NS_END
