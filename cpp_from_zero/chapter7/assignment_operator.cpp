#include <iostream>

class Copyable {
public:
    Copyable() : data_(new int(0)) {}

    // Copy constructor
    Copyable(const Copyable& c) : data_(new int(*c.data_)) {}

    ~Copyable() { delete data_; }

    // Copy assignment operator
    // Argument: const lvalue reference to a object being copied
    // Return: lvalue reference to this object
    Copyable& operator=(const Copyable& c) {
        *data_ = *(c.data_);

        return *this;
    }

private:
    int *data_;
};

class Movable {
public:
    Movable() : data_(new int(0)) {}

    // Move constructor
    Movable(Movable&& m) : data_(m.data_) { m.data_ = nullptr; }

    ~Movable() { delete data_; }

    // Move assignment operator
    // Argument: rvalue reference to a object being moved
    // Return: lvalue reference to this object
    Movable& operator=(Movable&& m) {
        delete data_;
        data_ = m.data_;
        m.data_ = nullptr;

        return *this;
    }

private:
    int* data_;
};

int main() {
    Copyable c1;
    Copyable c2 = c1; // Copy initialization: copy constructor is used
    Copyable c3;
    c3 = c2; // Copy assignment: copy assignment operator is used

    Movable m1;
    Movable m2 = std::move(m1); // Move initialization: move constructor is used
    Movable m3;
    m3 = std::move(m2); // Move assignment: move assignment operator is used

    return 0;
}
