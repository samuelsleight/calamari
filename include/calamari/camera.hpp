//
// Created by Sam Sleight on 20/01/2016.
//

#ifndef CALAMARI_CAMERA_HPP
#define CALAMARI_CAMERA_HPP

#include "defines.hpp"
#include "colour.hpp"

CALAMARI_NS

class State;
class Renderer;

class Camera {
public:
    virtual void register_component(calamari::State& state);

    Colour background;

private:
    friend class Renderer;

    void clear();
};

CALAMARI_NS_END

#endif //CALAMARI_CAMERA_HPP
