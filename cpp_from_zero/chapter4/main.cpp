#include <iostream>
#include "a.hpp"
#include "defs.hpp"

// Prototype declaration
void HelloWorld();

// Function definition
void HelloWorld() {
    std::cout << "Hello world!\n" << std::endl;
}

// Global variable
int gx = 100;

namespace A {
    int count = 2;

    int GetCount() {
        return count; // A::count
    }
} // namespace A

namespace B {
    int count = 3;

    // Nested namespace
    namespace P {
        int count = 4; // B::P::count

        int GetCount() {
            return count;
        }
    }
} // namespace B

namespace {
    int x_in_u = 5;
} // namespace

int main() {
    {
        int x = 100; // Variable definition and initialization
        // int x; // Definition cannot duplicated
    }

    {
        // Call function defined in "a.cpp"
        DoSomething();
        DoSomething2();
        DoSomething3();
        DoSomething4();
        DoSomething5();
    }

    {
        // Refer variable with scope resolution operator
        std::cout << A::count << std::endl; // 2
        std::cout << B::count << std::endl; // 3
        std::cout << B::P::GetCount() << std::endl; // 4

        int x = 3;
        {
            int x = 5;
            std::cout << x << std::endl; // 5
            // End of scope
        }
        {
            std::cout << x << std::endl; // 3
        }

        // Refer global variable
        std::cout << gx << std::endl; // 100

        int gx = 10;
        std::cout << gx << std::endl; // 10
        // Refer global scope with scope resolution operator
        std::cout << ::gx << std::endl; // 100
    }

    {
        // Link error: decleared in a.cpp, cannot refer here
        // std::cout << x_in_a << std::endl;

        // Decleared in the unnamed namespace in main.cpp / a.cpp
        // A definition does not be duplicated
        std::cout << x_in_u << std::endl;
    }

    {
        // Call inline function defined in defs.hpp
        // The definition is expected to be expanded at call site
        ProcInline();
    }

    return 0;
}
