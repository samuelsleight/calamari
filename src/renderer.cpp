//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/renderable.hpp"
#include "calamari/renderer.hpp"
#include "calamari/state.hpp"
#include "calamari/camera.hpp"

#include <iostream>

CALAMARI_NS

CALAMARI_GLSL(vertex_shader_source,
layout(location = 0) in vec2 position;

void main() {
    gl_Position = vec4(position, 0.0, 1.0);
});

CALAMARI_GLSL(fragment_shader_source,
out vec4 colour;

void main() {
    colour = vec4(1, 1, 1, 1);
});

Renderer::Renderer(Window& window) throw(InitialisationError)
    : window(window) {

    // Create attribute array
    GLuint vao;
    gl::GenVertexArrays(1, &vao);
    gl::BindVertexArray(vao);

    // Compile vertex shader
    GLuint vertex_shader = gl::CreateShader(gl::VERTEX_SHADER);
    gl::ShaderSource(vertex_shader, 1, &vertex_shader_source, nullptr);
    gl::CompileShader(vertex_shader);

    GLint status;
    gl::GetShaderiv(vertex_shader, gl::COMPILE_STATUS, &status);
    if(status != gl::TRUE_) {
        throw InitialisationError("Error compiling vertex shader");
    }

    // Compile fragment shader
    GLuint fragment_shader = gl::CreateShader(gl::FRAGMENT_SHADER);
    gl::ShaderSource(fragment_shader, 1, &fragment_shader_source, nullptr);
    gl::CompileShader(fragment_shader);

    gl::GetShaderiv(fragment_shader, gl::COMPILE_STATUS, &status);
    if(status != gl::TRUE_) {
        throw InitialisationError("Error compiling fragment shader");
    }

    // Create shader program
    shader_program = gl::CreateProgram();
    gl::AttachShader(shader_program, vertex_shader);
    gl::AttachShader(shader_program, fragment_shader);

    gl::LinkProgram(shader_program);
    gl::UseProgram(shader_program);
}

void Renderer::load_scene(State& state) {
    for(Renderable& renderable : state.renderables) {
        gl::GenBuffers(1, &renderable.vbo);
        gl::BindBuffer(gl::ARRAY_BUFFER, renderable.vbo);
        gl::BufferData(gl::ARRAY_BUFFER, renderable.vertices.size() * sizeof(float), &(renderable.vertices[0]), gl::STATIC_DRAW);
    }

    gl::BindBuffer(gl::ARRAY_BUFFER, 0);
}

void Renderer::render(State& state) {
    if(state.camera) {
        state.camera->clear_background();
    }

    GLint pos = gl::GetAttribLocation(shader_program, "position");
    for(Renderable& renderable : state.renderables) {
        gl::BindBuffer(gl::ARRAY_BUFFER, renderable.vbo);
        gl::VertexAttribPointer(pos, 2, gl::FLOAT, gl::FALSE_, 0, 0);
        gl::EnableVertexAttribArray(pos);
        gl::DrawArrays(gl::TRIANGLES, 0, renderable.vertices.size() / 2);
    }

    gl::DisableVertexAttribArray(pos);
    gl::BindBuffer(gl::ARRAY_BUFFER, 0);

    glfwSwapBuffers(this->window.window);
}

CALAMARI_NS_END
