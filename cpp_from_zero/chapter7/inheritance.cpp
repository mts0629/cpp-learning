#include <iostream>

// Base class
class Rectangle {
private: // Default, can be refered from this class only
    // int height_;
    // int width_;

protected: // Can be refered from this / derived class
    int height_;
    int width_;

public: // No limitation for reference
    int Area() const {
        return height_ * width_;
    }
};

// Derived class
// Rectangle class, inherit Rectangle class
class Square : public Rectangle {
public:
    void SetSize(int size) {
        // Refer data members in the base class
        height_ = size;
        width_ = size;
    }
};

class AccessSpecifier {
    // private in default
    void Private1() {};

public:
    void Public1() {};
    void Public2() {};

public: // No problem without members
private: // Access specifier can be used any number of times
    void Private2() {};

private: // No problem without changing access level
    void Private3() {};
};

class Base {};

class Sub1 : public Base {};    // public inheritance
class Sub2 : protected Base {}; // protected inheritance
class Sub3 : private Base {};   // private inheritance
class Sub4 : Base {};           // private inheritance in default

int main() {
    Square s;

    s.SetSize(10);
    std::cout << s.Area() << std::endl;

    return 0;
}
