//
// Created by Sam Sleight on 20/01/2016.
//

#include "calamari/gl/gl_core_3_3.hpp"
#include "calamari/camera.hpp"
#include "calamari/state.hpp"

CALAMARI_NS

void Camera::register_object(calamari::State& state) {
    state.set_camera(*this);
}

void Camera::clear() {
    gl::Clear(gl::COLOR_BUFFER_BIT);
    gl::ClearColor(1.0f, 0.0f, 1.0f, 1.0f);
}

CALAMARI_NS_END
