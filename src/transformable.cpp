//
// Created by Sam Sleight on 31/01/2016.
//

#include "calamari/transformable.hpp"

#include <cmath>

CALAMARI_NS

void Transformable::translate(float x, float y, float z) {
    push_transformation(translation(x, y, z));
}

void Transformable::rotate(Axis axis, float radians) {
    push_transformation(rotation(axis, radians));
}

Transformation Transformable::transformation() {
    return stack.transformation();
};

Transformation Transformable::pop_transformation() {
    return stack.pop_transformation();
}

Transformation Transformable::push_transformation(Matrix<4, 4, float> transformation) {
    stack.push_transformation(transformation);
}

CALAMARI_NS_END
