//
// Created by Sam Sleight on 31/01/2016.
//

#ifndef CALAMARI_TRANSFORMABLE_HPP
#define CALAMARI_TRANSFORMABLE_HPP

#include "defines.hpp"
#include "transformation.hpp"

CALAMARI_NS

class Transformable {
public:
    void translate(float x, float y, float z);
    void rotate(Axis axis, float radians);

    Transformation transformation();
    Transformation pop_transformation();
    Transformation push_transformation(Matrix<4, 4, float> transformation);

private:
    TransformationStack stack;
};

CALAMARI_NS_END

#endif //CALAMARI_TRANSFORMABLE_HPP
