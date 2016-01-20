//
// Created by Sam Sleight on 20/01/2016.
//

#ifndef CALAMARI_CAMERA_HPP
#define CALAMARI_CAMERA_HPP

#include "defines.hpp"

CALAMARI_NS

class State;
class Renderer;

class Camera {
public:
    virtual void register_object(calamari::State& state);

private:
    friend class Renderer;

    void clear();
};

CALAMARI_NS_END

#endif //CALAMARI_CAMERA_HPP
