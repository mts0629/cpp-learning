#include <iostream>

// Class template
template <typename T>
class Rectangle {
public:
    Rectangle(T height, T width) :
        height_(height), width_(width) {}

    T Area() const {
        return height_ * width_;
    }

private:
    T height_;
    T width_;
};

// Using 2 template parameters
template<typename T, typename U>
class Rectangle2 {
public:
    Rectangle2(T height, U width) :
        height_(height), width_(width) {}

    auto Area() const ->
        // Type inference for the data type of return value by
        // decltype and std::declval
        decltype(std::declval<T>() * std::declval<U>()) {
        return height_ * width_;
    }

private:
    T height_;
    U width_;
};

// Using non-type template parameter
template <typename T, int N>
class Array {
public:
    int size() const {
        return N;
    }

private:
    T data_[N];
};

int main() {
    // Instantiate class template
    // Cannot omit specifying data type
    Rectangle<int> r1(10, 20);
    Rectangle<double> r2(1.2, 3.4);
    std::cout << r1.Area() << std::endl;
    std::cout << r2.Area() << std::endl;

    // 2 template paramerers
    Rectangle2<int, double> r2_1(10, 3.14);
    std::cout << r2_1.Area() << std::endl;

    // Type and non-type parameters
    Array<int, 5> array;
    std::cout << array.size() << std::endl;

    return 0;
}
