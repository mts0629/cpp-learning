#include <iostream>

class Rectangle {
public:
    // Default constructor
    // Defined by a compiler implicitly if any constructor is not defined
    Rectangle() :
        // Member initializer
        height_(0), width_(0) {
        std::cout << "Rectangle: default constructor" << std::endl;
    };

    // Constructor
    Rectangle(int height, int width);

    // Converting constructor: receives only one parameter
    // Implicit type conversion doesn't be occured by "explicit"
    explicit Rectangle(int size) :
        height_(size), width_(size) {
        std::cout << "Rectangle: converting constructor" << std::endl;
    }

    // Copy constructor: only receives a reference of this class
    // Defined by the compiler implicitly
    Rectangle(const Rectangle& r) :
        height_(r.height_), width_(r.width_) {
        std::cout << "Rectangle: copy constructor" << std::endl;
    }

    // Move constructor: only receives a r-value reference of this class
    // Defined by the compiler implicitly
    Rectangle(const Rectangle&& r) :
        height_(r.height_), width_(r.width_) {
        std::cout << "Rectangle: move constructor" << std::endl;
    }

    int Area() const {
        return this->height_ * this->width_;
    }

private:
    const int height_;
    const int width_;
};

// Define a constructor outside the class
Rectangle::Rectangle(int height, int width) :
    height_(height), width_(width) {
    std::cout << "Rectangle::Rectangle(int height, int width)" << std::endl;
}

class Square : public Rectangle {
public:
    Square() {
        std::cout << "Square::Square()" << std::endl;
    }

    // Call a specific constructor of the base class explicitly
    Square(int size) : Rectangle(size, size) {
        std::cout << "Square::Square(int size)" << std::endl;
    }
};

int main() {
    Rectangle r1(10, 20);
    std::cout << "r1.Area() = " << r1.Area() << std::endl;

    Rectangle r2;
    std::cout << "r2.Area() = " << r2.Area() << std::endl;

    Rectangle r3(r1);
    std::cout << "r3.Area() = " << r3.Area() << std::endl;

    Rectangle r4(std::move(r1));
    std::cout << "r4.Area() = " << r4.Area() << std::endl;

    // Implicit type conversion makes a compilation error by "explicit"
    // Rectangle r5 = 10;
    Rectangle r5(10);
    std::cout << "r5.Area() = " << r5.Area() << std::endl;

    // A constructor of the base class is called before that of the derived class
    Square s1;
    std::cout << "s1.Area() = " << s1.Area() << std::endl;

    Square s2(10);
    std::cout << "s2.Area() = " << s2.Area() << std::endl;

    return 0;
}
