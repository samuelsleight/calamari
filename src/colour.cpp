//
// Created by Sam Sleight on 20/01/2016.
//

#include "calamari/colour.hpp"

CALAMARI_NS

Colour::Colour() : Colour(1, 1, 1, 1) {}

Colour::Colour(float r, float g, float b, float a) : Vector<4, float>(r, g, b, a) {}

const Colour Colour::red = Colour(1.0, 0.0, 0.0);
const Colour Colour::green = Colour(0.0, 1.0, 0.0);
const Colour Colour::blue = Colour(0.0, 0.0, 1.0);

CALAMARI_NS_END
