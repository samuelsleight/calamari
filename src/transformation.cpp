//
// Created by Sam Sleight on 31/01/2016.
//

#include "calamari/transformation.hpp"

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

Matrix<4, 4, float> TransformationStack::get_total_transformation() {
    if(stack) {
        return stack->transformation.total;
    } else {
        return Matrix<4, 4, float>(
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        );
    }
};

CALAMARI_NS_END
