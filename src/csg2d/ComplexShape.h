//
// Created by jakub on 20.05.2024.
//

#ifndef CONSOLE_PPG2LAB12_COMPLEXSHAPE_H
#define CONSOLE_PPG2LAB12_COMPLEXSHAPE_H

#include "shape.h"
#include "operation.h"

namespace CSG2D{
    class ComplexShape : public Shape{
    private:
        std::shared_ptr<Shape> shape1_;
        std::shared_ptr<Shape> shape2_;
        const OPERATION operation_;
    public:
        ComplexShape(std::shared_ptr<Shape> shape1, std::shared_ptr<Shape> shape2, const OPERATION& operation); //: shape1_(shape1), shape2_(shape2), operation(OPERATION){}
        [[nodiscard]] bool isIn(const sf::Vector2f& test_position) const override;
    };
}


#endif //CONSOLE_PPG2LAB12_COMPLEXSHAPE_H
