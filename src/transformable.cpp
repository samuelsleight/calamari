//
// Created by Sam Sleight on 31/01/2016.
//

#include "calamari/transformable.hpp"

CALAMARI_NS

void Transformable::translate(float x, float y, float z) {
    transformation.push_transformation(Matrix<4, 4, float>(
        1, 0, 0, x,
        0, 1, 0, y,
        0, 0, 1, z,
        0, 0, 0, 1
    ));
}

Matrix<4, 4, float> Transformable::translation() {
    return transformation.get_total_transformation();
};

CALAMARI_NS_END
