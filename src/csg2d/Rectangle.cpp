//
// Created by jakub on 20.05.2024.
//

#include "Rectangle.h"
//#include "functions.h"
namespace CSG2D{
    Rectangle::Rectangle(float x, float y, const sf::Vector2f &pos, float rotation) : CSG2D::Shape(pos, rotation), x_(x), y_(y){}

    bool Rectangle::isIn(const sf::Vector2f &test_position) const {
        sf::Vector2f point_position = test_position-position_;

        float cs = std::cos(-1 * this->angle_rad_);
        float sn = std::sin(-1 * this->angle_rad_);
        float x = point_position.x*cs - point_position.y*sn;
        float y = point_position.x*sn + point_position.y*cs;
        sf::Vector2f rotated;
        rotated.x = x;
        rotated.y = y;


        //sf::Vector2f rotated = rotate(point_position, -angle_rad_);
        // if(point_position.x() <= x_/2 && point_position.y() <=y_/2)
        return (abs(rotated.x) <= x_/2 && abs(rotated.y) <=y_/2);
    }
}


