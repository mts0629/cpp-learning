#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"

class Circle {
public:
    Circle(const Point& center, double radius)
        : center_(center), radius_(radius) {}

    Point Center() const {
        return center_;
    }

    double Radius() const {
        return radius_;
    }

private:
    Point center_;
    double radius_;
};

#endif // CIRCLE_HPP
