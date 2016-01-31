//
// Created by Sam Sleight on 20/01/2016.
//

#ifndef CALAMARI_CAMERA_HPP
#define CALAMARI_CAMERA_HPP

#include "defines.hpp"
#include "colour.hpp"
#include "vector.hpp"
#include "transformable.hpp"

CALAMARI_NS

class State;
class Renderer;

class Camera : public Transformable {
public:
    virtual void register_component(calamari::State& state);

    Colour background;
    Vector<2, int> viewport;

private:
    friend class Renderer;

    void clear_background();
};

CALAMARI_NS_END

#endif //CALAMARI_CAMERA_HPP
