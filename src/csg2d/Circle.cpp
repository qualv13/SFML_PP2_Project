//
// Created by jakub on 20.05.2024.
//
#include <algorithm>
#include "Circle.h"

namespace CSG2D{
    Circle::Circle(float r, const sf::Vector2f &pos) : CSG2D::Shape(pos, 0), radius(r){}

    bool Circle::isIn(const sf::Vector2f &test_position) const {

        float distance = sqrt((test_position.x- position_.x) * (test_position.x- position_.x) + (test_position.y- position_.y) * (test_position.y- position_.y));

        return (distance <= radius);
    }


}
