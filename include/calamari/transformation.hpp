//
// Created by Sam Sleight on 31/01/2016.
//

#ifndef CALAMARI_TRANSFORMATION_HPP
#define CALAMARI_TRANSFORMATION_HPP

#include "defines.hpp"
#include "matrix.hpp"

#include <memory>

CALAMARI_NS

enum class Axis {
    X, Y, Z
};

struct Transformation {
    Transformation(Matrix<4, 4, float> transformation, Matrix<4, 4, float> total);

    Matrix<4, 4, float> transformation;
    Matrix<4, 4, float> total;
};

struct TransformationNode {
    TransformationNode(Transformation transformation, std::shared_ptr<TransformationNode> next);

    Transformation transformation;
    std::shared_ptr<TransformationNode> next;
};

class TransformationStack {
public:
    TransformationStack();

    void push_transformation(Matrix<4, 4, float> transformation);

    Transformation transformation();
    Transformation pop_transformation();

private:
    std::shared_ptr<TransformationNode> stack;
};

Matrix<4, 4, float> translation(float x, float y, float z);
Matrix<4, 4, float> rotation(Axis axis, float radians);

CALAMARI_NS_END

#endif //CALAMARI_TRANSFORMATION_HPP
