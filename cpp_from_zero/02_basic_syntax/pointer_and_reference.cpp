#include <iostream>

int main() {
    int x = 5;

    // Pointer to int
    int* p = &x;
    std::cout << "p = " << p << std::endl;
    // Dereference
    std::cout << "*p = " << *p << std::endl;

    // Null pointer
    p = nullptr;

    // Pointer to const int
    const int* pc = &x;
    // Compilation error
    // *pc = 123;
    int y = 6;
    pc = &y; // OK

    // Const pointer to int
    int* const cp = &x;
    // cp = &y; // Compilation error
    *cp = 6; // OK

    // Const pointer to const int
    const int* const cpc = &x;
    // Compilation error
    // cpc = &y;
    // *cpc = 6;

    // Reference
    int& r = x; // Initializer is mandatory
    // Can be used in a similar way with a normal variable
    std::cout << "r = " << r << std::endl;
    r = 100;
    std::cout << "r = " << r << std::endl;

    return 0;
}
