//
// Created by Sam Sleight on 20/01/2016.
//

#ifndef CALAMARI_COLOUR_HPP
#define CALAMARI_COLOUR_HPP

#include "defines.hpp"
#include "vector.hpp"

CALAMARI_NS

struct Colour : public Vector<4, float> {
    Colour();
    Colour(float r, float g, float b, float a = 1.0);

    float& r = Vector<4, float>::data[0];
    float& g = Vector<4, float>::data[1];
    float& b = Vector<4, float>::data[2];
    float& a = Vector<4, float>::data[3];

    // Default Colours
    static const Colour red;
    static const Colour green;
    static const Colour blue;
};

CALAMARI_NS_END

#endif //CALAMARI_COLOUR_HPP
