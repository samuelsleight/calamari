//
// Created by Sam Sleight on 18/01/2016.
//

#include "calamari/renderable.hpp"
#include "calamari/renderer.hpp"
#include "calamari/state.hpp"
#include "calamari/camera.hpp"

CALAMARI_NS

CALAMARI_GLSL(vertex_shader_source,
layout(location = 0) in vec3 position;

void main() {
    gl_Position = vec4(position, 1);
});

CALAMARI_GLSL(fragment_shader_source,
out vec4 colour;

void main() {
    colour = vec4(1, 0, 0, 1);
});

namespace impl {

GLuint create_shader(GLenum shader_type, const GLchar** shader_source, const char* error_message) {
    GLuint shader = gl::CreateShader(shader_type);
    gl::ShaderSource(shader, 1, shader_source, nullptr);
    gl::CompileShader(shader);

    GLint status;
    gl::GetShaderiv(shader, gl::COMPILE_STATUS, &status);
    if (status != gl::TRUE_) {
        throw InitialisationError(error_message);
    }

    return shader;
}

}

Renderer::Renderer(Window& window) throw(InitialisationError)
    : window(window) {

    // Create attribute array
    GLuint vao;
    gl::GenVertexArrays(1, &vao);
    gl::BindVertexArray(vao);

    // Compile shaders
    GLuint vertex_shader = impl::create_shader(gl::VERTEX_SHADER, &vertex_shader_source, "Error compiling vertex shader");
    GLuint fragment_shader = impl::create_shader(gl::FRAGMENT_SHADER, &fragment_shader_source, "Error compiling fragment shader");

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
        gl::Viewport(0, 0, state.camera->viewport.x, state.camera->viewport.y);

        GLint pos = gl::GetAttribLocation(shader_program, "position");
        for(Renderable& renderable : state.renderables) {
            gl::BindBuffer(gl::ARRAY_BUFFER, renderable.vbo);
            gl::VertexAttribPointer(pos, 3, gl::FLOAT, gl::FALSE_, 0, 0);
            gl::EnableVertexAttribArray(pos);
            gl::DrawArrays(gl::TRIANGLES, 0, renderable.vertices.size() / 3);
        }

        gl::DisableVertexAttribArray(pos);
        gl::BindBuffer(gl::ARRAY_BUFFER, 0);

        glfwSwapBuffers(this->window.window);
    }

}

CALAMARI_NS_END
