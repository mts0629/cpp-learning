#include <iostream>

// Class
class Rectangle {
private:
    // Data members, private
    int height_;
    int width_;

public:
    // Member functions
    // If a function is defined in the class declaration,
    // it is implicity specified as inline function
    void SetHeight(const int height) {
        this->height_ = height;
    }

    void SetWidth(const int width) {
        this->width_ = width;
    }

    // Const member function
    int Area() const;
};

// Member function definition
int Rectangle::Area() const {
    // Refer data members with this pointer
    // Compile error: cannot modify the data member in a const member function
    // this->height_ = 10;
    return this->height_ * this->width_;
}

int main() {
    Rectangle r;

    // Member access
    r.SetHeight(10);
    r.SetWidth(20);
    std::cout << r.Area() << std::endl;

    // Pointer accesss
    Rectangle* pr = &r;
    std::cout << (*pr).Area() << std::endl;
    std::cout << pr->Area() << std::endl;

    return 0;
}
