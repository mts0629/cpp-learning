#include <iostream>

#include "counter.hpp"

class Brightness {
public:
    explicit Brightness(int value) : value_(value) {}

    int Value() const {
        return value_;
    }

    // Declear static member functions
    static Brightness Maximum();
    static Brightness Minimum();
    static Brightness Median();

private:
    int value_;
};

// Define static member functions
Brightness Brightness::Maximum() {
    return Brightness(100);
}

Brightness Brightness::Minimum() {
    return Brightness(0);
}

// protected / private members can be accessed
Brightness Brightness::Median() {
    return Brightness((Maximum().value_ + Minimum().value_) / 2);
}

int main() {
    // Refer a static data member
    ++Counter::count_;
    std::cout << Counter::count_ << std::endl;

    Brightness b = Brightness::Median();
    std::cout << b.Value() << std::endl;

    return 0;
}
