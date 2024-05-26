//
// Created by jakub on 20.05.2024.
//

#include "ComplexShape.h"

namespace CSG2D{
    ComplexShape::ComplexShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, const OPERATION &operation):
                               shape1_(shape1), shape2_(shape2), operation_(operation), Shape(sf::Vector2f(0,0), 0){

    }

    bool ComplexShape::isIn(const sf::Vector2f &test_position) const {
        if (operation_ == OPERATION::UNION){
            return shape1_->isIn(test_position) || shape2_->isIn(test_position);
        }
        if (operation_ == OPERATION::DIFFERENCE){
            return shape1_->isIn(test_position) && !shape2_->isIn(test_position);
        }
        if (operation_ == OPERATION::INTERSECTION){
            return shape1_->isIn(test_position) &&  shape2_->isIn(test_position);
        }
        return false;
    }
}

