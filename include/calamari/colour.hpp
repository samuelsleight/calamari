//
// Created by Sam Sleight on 20/01/2016.
//

#ifndef CALAMARI_COLOUR_HPP
#define CALAMARI_COLOUR_HPP

#include "defines.hpp"

CALAMARI_NS

struct Colour {
    Colour();
    Colour(float r, float g, float b, float a = 1.0);

    float r, g, b, a;

    // Default Colours
    static const Colour red;
    static const Colour green;
    static const Colour blue;
};

CALAMARI_NS_END

#endif //CALAMARI_COLOUR_HPP
