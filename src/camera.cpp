//
// Created by Sam Sleight on 20/01/2016.
//

#include "calamari/gl/gl_core_3_3.hpp"
#include "calamari/camera.hpp"
#include "calamari/state.hpp"

CALAMARI_NS

void Camera::register_component(calamari::State& state) {
    state.set_camera(*this);
}

void Camera::clear_background() {
    gl::Clear(gl::COLOR_BUFFER_BIT);
    gl::ClearColor(background.r, background.g, background.b, background.a);
}

CALAMARI_NS_END
