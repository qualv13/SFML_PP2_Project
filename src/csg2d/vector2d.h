#ifndef CW3_VECTOR2D_H
#define CW3_VECTOR2D_H


class Vector2D {
private:
    double x_;
    double y_;
    static double eps;
public:
    static void compEpsilon(double a);

    Vector2D();
    Vector2D(double x, double y);

    Vector2D add(const Vector2D& v) const;
    Vector2D minus(const Vector2D& v) const;
    Vector2D operator+(const Vector2D& v) const;
    Vector2D subtract(const Vector2D& v) const;
    Vector2D operator-(const Vector2D& v) const;

    double dot(const Vector2D& v1) const;
    double length() const;
    double lengthSq() const;
    Vector2D perpendicular() const;

    //Vector2D& operator=(Vector2D& v);

    void operator+=(const Vector2D& v);
    void operator-=(const Vector2D& v);
    void operator*=(const double a);

    bool operator==(const Vector2D& v) const;
    bool operator!=(const Vector2D& v) const;

    Vector2D multiply(double a) const;
    Vector2D operator*(double a) const;

    double x() const;
    double y() const;


    Vector2D& x(double value);
    Vector2D& y(double value);
};


#endif //CW3_VECTOR2D_H