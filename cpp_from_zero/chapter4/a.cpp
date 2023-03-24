#include "a.hpp"

#include <iostream>

// Internal linkage in a.cpp
static int x_in_a = 246;

// Unnamed namespace: internal linkage
namespace {
    int x_in_u = 50;
} // namespace

// Definitions
void DoSomething() {
    std::cout << "DoSomething" << std::endl;
}

void DoSomething2() {
    std::cout << "DoSomething2" << std::endl;
}

void DoSomething3() {
    std::cout << "DoSomething3" << std::endl;
}

void DoSomething4() {
    std::cout << "DoSomething4" << std::endl;
}

void DoSomething5() {
    std::cout << "DoSomething5" << std::endl;
}
