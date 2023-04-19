#include <iostream>

#include "circle.hpp"

double SquareOf(double v) {
    return v * v;
}

double SquareOfDistance(const Point& p, const Point& q) {
    return SquareOf(q.X() - p.X()) - SquareOf(q.Y() - p.Y());
}

bool Intersects(const Circle& c1, const Circle& c2) {
    auto c = SquareOfDistance(c1.Center(), c2.Center());
    auto r = SquareOf(c1.Radius() + c2.Radius());
    return c < r;
}

int main() {
    Circle c1(Point(1, 2), 3);
    Circle c2(Point(5, 0), 2);

    if (Intersects(c1, c2)) {
        std::cout << "2 circles intersect" << std::endl;
    } else {
        std::cout << "2 circles doesn't intersect" << std::endl;
    }

    return 0;
}
