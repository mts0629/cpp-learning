#include <iostream>
#include "a.hpp"

// Prototype declaration
void HelloWorld();

// Function definition
void HelloWorld() {
    std::cout << "Hello world!\n" << std::endl;
}

int main() {
    {
        int x = 100; // Variable definition and initialization
        // int x; // Definition cannot duplicate
    }

    {
        // Call function defined in "a.cpp"
        DoSomething();
        DoSomething2();
        DoSomething3();
        DoSomething4();
        DoSomething5();
    }

    return 0;
}
