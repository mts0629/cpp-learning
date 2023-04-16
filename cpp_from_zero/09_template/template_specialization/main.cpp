#include <iostream>

#include "sum.hpp"

// Extern template:
// instantiate function template with specified type parameters
template int Sum<int>(int, int);

template <typename T>
T DoSomething(T a, T b) {
    return a + b;
}

// Explicit specialization:
// change behavior for specific template parameter
template <>
double DoSomething<double>(double a, double b) {
    return a * b;
}

template <typename T>
class Array {
public:
    explicit Array(int size) :
        size_(size), data_(new T[size_]) {}

    ~Array() {
        delete[] data_;
    }

    int Size() const {
        return size_;
    }

private:
    const int size_;
    T* data_;
};

// Explicit specialization of class template, for bool
template<>
class Array<bool> {
public:
    explicit Array(int size) :
        size_(size), data_size_((size - 1) / 8 + 1),
        data_(new uint8_t[data_size_]) {}

    ~Array() {
        delete[] data_;
    }

    int DataSize() const {
        return data_size_;
    }

    int Size() const {
        return size_;
    }

private:
    const int size_;
    const int data_size_;
    uint8_t* data_;
};

int main() {
    // Implicit instantiation (by a compiler)
    std::cout << Sum(1, 2) << std::endl;

    // A function template is used
    std::cout << DoSomething(2, 3) << std::endl; // 5
    // The template is specialized for double
    std::cout << DoSomething(2.0, 3.0) << std::endl; // 6.0

    Array<int> a1(10);
    // Specialized class template is used
    Array<bool> a2(10);

    std::cout << a1.Size() << std::endl;
    std::cout << a2.DataSize() << std::endl;
    std::cout << a2.Size() << std::endl;

    return 0;
}
