#include "vector2d.h"
#include <math.h>


double Vector2D::eps = 0;

void Vector2D::compEpsilon(double a) {
    eps = a;
}

Vector2D::Vector2D(): x_(0), y_(0) {}

Vector2D::Vector2D(double x, double y): x_(x), y_(y) {}

Vector2D Vector2D::add(const Vector2D &v) const {
    return {
            x_ + v.x_,
            y_ + v.y_,
    };
}

Vector2D Vector2D::minus(const Vector2D &v) const {
    return {
            x_ - v.x_,
            y_ - v.y_,
    };
}

Vector2D Vector2D::operator+(const Vector2D &v) const {
    return add(v);
}

Vector2D Vector2D::subtract(const Vector2D &v) const {
    return {
            x_ - v.x_,
            y_ - v.y_,
    };
}

Vector2D Vector2D::operator-(const Vector2D &v) const {
    return subtract(v);
}


double Vector2D::dot(const Vector2D &v1) const {
    return v1.x_*x_ + y_*v1.y_;
}

double Vector2D::length() const {
    return sqrt(lengthSq());
}

inline double Vector2D::lengthSq() const { //inline wstawia tutaj kod z dot() i dzięki temu jest efektywniej,
    return dot(*this); //można też zamiast inline tutaj, wkleić zawartość klamrowych do deklaracji i będzie działać tak samo
}


Vector2D Vector2D::perpendicular() const {
    return Vector2D(y_, x_*(-1));
}

/*Vector2D& Vector2D::operator=(Vector2D &v) {
    x_ = v.x_; y_ = v.y_;
}*/


// Vector2D& Vector2D::operator-=(const Vector2D& v2){
// *this = (*this) - v2;
// return *this
// }
void Vector2D::operator+=(const Vector2D &v)  {
    *this = add(v);
    //x_ = x_ + v.x_; y_ = y_ + v.y_;
    //return Vector2D(x_, y_);
}

void Vector2D::operator-=(const Vector2D &v) {
    *this = minus(v);
    //x_ = x_ - v.x_; y_ = y_ - v.y_;
    //return Vector2D(x_, y_);
}

void Vector2D::operator*=(const double a) {
    *this = multiply(a);
    //x_ *=a; y_ *=a;
    //return Vector2D(x_, y_);
}

bool Vector2D::operator==(const Vector2D &v) const {
    double a, b;
    if(x_ - v.x_ > 0){
        a = x_ - v.x_;
    }else{
        a = v.x_ - x_;
    }
    if(y_ - v.y_ > 0){
        b = y_ - v.y_;
    } else{
        b = v.y_ - y_;
    }

    if( a <= eps && b <= eps){
        return 1;
    }
    return 0;
}

bool Vector2D::operator!=(const Vector2D &v) const {
    double a, b;
    if(x_ - v.x_ > 0){
        a = x_ - v.x_;
    }else{
        a = v.x_ - x_;
    }
    if(y_ - v.y_ > 0){
        b = y_ - v.y_;
    } else{
        b = v.y_ - y_;
    }
    if( a > eps && b > eps){
        return 1;
    }
    return 0;
}

Vector2D Vector2D::multiply(double a) const {
    return {
            x_ * a,
            y_ * a
    };
}

Vector2D Vector2D::operator*(double a) const {
    return multiply(a);
}

double Vector2D::x() const {
    return x_;
}

double Vector2D::y() const {
    return y_;
}

Vector2D& Vector2D::x(double value) {
    x_ = value;
    return *this;
}

Vector2D& Vector2D::y(double value) {
    y_ = value;
    return *this;
}