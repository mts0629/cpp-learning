#include <iostream>

#include "other.hpp"

namespace {
    int hoge = 0; // hoge in main.cpp
}

int main() {
    // Link error: decleared in other.cpp, cannot refer from here
    // std::cout << x_in_other_cpp << std::endl;

    Print();
    // Cannot refer from here
    // std::cout << x << std::endl;

    IncrementHoge();

    // Decleared in main.cpp and other.cpp
    // The definition can be duplicated by internal linkage
    std::cout << "main.cpp: " << hoge << std::endl;

    PrintHoge(); // hoge in other.cpp is refered

    return 0;
}
