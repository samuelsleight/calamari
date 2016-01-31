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

    Matrix<4, 4, float> translation();

private:
    TransformationStack transformation;
};

CALAMARI_NS_END

#endif //CALAMARI_TRANSFORMABLE_HPP
