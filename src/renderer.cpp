//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/renderer.hpp"

CALAMARI_NS

Renderer::Renderer(Window& window)
    : window(window) {}

void Renderer::render() {
    glfwSwapBuffers(this->window.window);
}

void Renderer::clear(float r, float a, float g, float b) {
    gl::Clear(gl::COLOR_BUFFER_BIT);
    gl::ClearColor(r, g, b, a);
}

CALAMARI_NS_END
