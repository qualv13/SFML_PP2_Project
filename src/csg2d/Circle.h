//
// Created by jakub on 20.05.2024.
//

#ifndef CONSOLE_PPG2LAB12_CIRCLE_H
#define CONSOLE_PPG2LAB12_CIRCLE_H

#include "shape.h"
#include "libincludes.h"
#include "functions.h"

namespace CSG2D {
    class Circle : public Shape {
    private:
        float radius;
    public:
        Circle(float r, const sf::Vector2f& pos);
        bool isIn(const sf::Vector2f& test_position) const override;
    };
}

#endif //CONSOLE_PPG2LAB12_CIRCLE_H
