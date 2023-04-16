#include <iostream>

// Abstruct class
// A class which has a pure virtual function cannot be instantiated
class Polygon {
public:
    // Pure virtual function
    virtual int Area() const = 0;
};

// The class which all member functions of are pure virtual function
// is used as an "interface"
class Rectangle : public Polygon {
public:
    int Area() const {
        return height_ * width_;
    }

    // Virtual function
    virtual void Describe() const {
        std::cout << "height = " << this->height_ << std::endl;
        std::cout << "width = "  << this->width_  << std::endl;
    }

    int height_;
    int width_;
};

class Square : public Rectangle {
public:
    void SetSize(int size) {
        this->height_ = size;
        this->width_ = size;
    }

    // Override of virtual function
    void Describe() const override {
        std::cout << "size = " << this->height_ << std::endl;
    }
};

int main() {
    Square s;
    s.SetSize(10);

    // Upcast: cast from reference of derived class to that of base class
    const Rectangle& r = s;
    std::cout << "area = " << r.Area() << std::endl;

    // Square::Descirbe() is called
    r.Describe();

    return 0;
}
