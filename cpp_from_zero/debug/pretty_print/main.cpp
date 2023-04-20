struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}
};

struct Triangle {
    Point a;
    Point b;
    Point c;

    Triangle(const Point& a, const Point& b, const Point& c)
        : a(a), b(b), c(c) {}
};

int main() {
    Triangle t(Point(1, 1), Point(2, 0), Point(3, 2));

    return 0;
}
