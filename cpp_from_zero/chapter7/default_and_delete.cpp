#include <iostream>

// Member functions being defined implicitly
// - Default construcor
// - Copy constructor
// - Copy assignment operator
// - Move constructor
// - Move assignment operator
// - Destructor

class Square {
public:
    explicit Square(int size) : size_(size) {}

    // Default constructor is not defined implicitly
    // because Square::Square(int) is defined
    // Define the default constructor explictly
    Square() = default;

    int Area() const {
        return size_ * size_;
    }

private:
    int size_;
};

class NonCopyable {
public:
    NonCopyable() = default;

    // Delete copy constructor and copy assignment operator
    // It makes this class uncopyable
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

private:
    int data_;
};

int main() {
    Square s1; // Default constructor is called
    Square s2(10);

    // Data members by built-in type are not initialized by the default constructor,
    // therefore s1.Area() returns an unstable value
    std::cout << "s1.Area() = " << s1.Area() << std::endl;
    std::cout << "s2.Area() = " << s2.Area() << std::endl;

    NonCopyable c1;
    // Compilation error: copy construcor is deleted
    // NonCopyable c2 = c1;
    NonCopyable c2;
    // Compilation error: copy assignment operator is deleted
    // c2 = c1;

    return 0;
}
