//
// Created by jakub on 20.05.2024.
//

#ifndef CONSOLE_PPG2LAB12_RECTANGLE_H
#define CONSOLE_PPG2LAB12_RECTANGLE_H

#include "shape.h"
#include "vector2d.h."

namespace CSG2D{
    class Rectangle : public Shape{
    private:
        float x_;
        float y_;
    public:
        Rectangle(float x, float y, const sf::Vector2f& pos, float rotation);
        bool isIn(const sf::Vector2f& test_position) const override;
    };

}



#endif //CONSOLE_PPG2LAB12_RECTANGLE_H
