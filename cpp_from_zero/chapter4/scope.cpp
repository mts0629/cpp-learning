#include <iostream>

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

int GetCount() {
    int cnt = 5;  // Function scope
    return cnt;
}

int main() {
    // Refer variable with scope resolution operator
    std::cout << A::count << std::endl; // 2
    std::cout << B::count << std::endl; // 3
    std::cout << B::P::GetCount() << std::endl; // 4

    // cnt in main() and in GetCount() have different scope
    int cnt = GetCount();

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

    return 0;
}
