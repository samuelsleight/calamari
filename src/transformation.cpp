//
// Created by Sam Sleight on 31/01/2016.
//

#include "calamari/transformation.hpp"

#include <cmath>

CALAMARI_NS

TransformationStack::TransformationStack() : stack(nullptr) {}

TransformationNode::TransformationNode(Transformation transformation, std::shared_ptr<TransformationNode> next)
    : transformation(transformation), next(next) {}

Transformation::Transformation(Matrix<4, 4, float> transformation, Matrix<4, 4, float> total)
    : transformation(transformation), total(total) {}

void TransformationStack::push_transformation(Matrix<4, 4, float> transformation) {
    if(stack) {
        stack = std::shared_ptr<TransformationNode>(new TransformationNode(
            {transformation, transformation * stack->transformation.total},
            std::move(stack)
        ));
    } else {
        stack = std::shared_ptr<TransformationNode>(new TransformationNode(
            {transformation, transformation},
            nullptr
        ));
    }
}

Transformation TransformationStack::transformation() {
    if(stack) {
        return stack->transformation;
    } else {
        return {
            Matrix<4, 4, float>(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            ),

            Matrix<4, 4, float>(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            ),
        };
    }
};

Transformation TransformationStack::pop_transformation() {
    Transformation ret = transformation();

    if(stack) {
        stack = stack->next;
    }

    return ret;
}

Matrix<4, 4, float> translation(float x, float y, float z) {
   return Matrix<4, 4, float>(
       1, 0, 0, x,
       0, 1, 0, y,
       0, 0, 1, z,
       0, 0, 0, 1
   );
}

Matrix<4, 4, float> rotation(Axis axis, float radians) {
    switch(axis) {
        case Axis::X:
            return Matrix<4, 4, float>(
                1, 0, 0, 0,
                0, cos(radians), -sin(radians), 0,
                0, sin(radians), cos(radians), 0,
                0, 0, 0, 1
            );

        case Axis::Y:
            return Matrix<4, 4, float>(
                cos(radians), 0, sin(radians), 0,
                0, 1, 0, 0,
                -sin(radians), 0, cos(radians), 0,
                0, 0, 0, 1
            );

        case Axis::Z:
            return Matrix<4, 4, float>(
                cos(radians), -sin(radians), 0, 0,
                sin(radians), cos(radians), 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            );
    }
}

CALAMARI_NS_END
