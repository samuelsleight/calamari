//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/renderer.hpp"
#include "calamari/state.hpp"
#include "calamari/camera.hpp"

CALAMARI_NS

Renderer::Renderer(Window& window)
    : window(window) {}

void Renderer::render(State& state) {
    if(state.camera) {
        state.camera->clear();
    }

    glfwSwapBuffers(this->window.window);
}

CALAMARI_NS_END
