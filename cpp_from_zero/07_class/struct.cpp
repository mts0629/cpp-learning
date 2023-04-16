#include <iostream>

// struct
struct Rectangle {
    // public is used in default as an access specifier
    int height;
    int width;

    int Area() const {
        return height * width;
    }
};

int main() {
    Rectangle r;
    r.height = 10;
    r.width = 20;

    std::cout << r.Area() << std::endl;

    return 0;
}
