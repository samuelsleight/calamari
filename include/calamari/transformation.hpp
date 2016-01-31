//
// Created by Sam Sleight on 31/01/2016.
//

#ifndef CALAMARI_TRANSFORMATION_HPP
#define CALAMARI_TRANSFORMATION_HPP

#include "defines.hpp"
#include "matrix.hpp"

#include <memory>

CALAMARI_NS

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

    Matrix<4, 4, float> get_total_transformation();

private:
    std::shared_ptr<TransformationNode> stack;
};

CALAMARI_NS_END

#endif //CALAMARI_TRANSFORMATION_HPP
