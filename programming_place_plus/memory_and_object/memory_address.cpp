#include <iostream>
#include <vector>

// Object is ...
// - On the memory
// - Enble to be named
// - Having the type
// - Having the lifetime

int main() {
    int a {};
    short b {};
    long long c {};

    // Pointer type
    int* pa {&a};
    short* pb {&b};
    long long* pc {&c};

    // Reference
    int& r {a};
    // "Pointer to a reference" does not exist,
    // a pointer to an integer is aquired
    int* pr {&r};

    // Show addresses
    std::cout << pa << "\n"
              << pb << "\n"
              << pc << "\n"
              << pr << "\n\n";

    char ch {'A'};
    // Casting is required for a pointer to a char in std::cout
    std::cout << static_cast<void*>(&ch) << "\n\n";

    struct S {
        int a;
        short b;
        long long c;
    };

    S s {};
    S *ps {&s};
    // Data members in the struct is placed in-order
    // when the same access control is used, and for non-static data members
    // Sometime "padding" is inserted between members
    std::cout << &s.a << "\n"
              << &s.b << "\n"
              << &s.c << "\n\n";

    // Offset of the data members, only for POD (Plain Old Data)
    std::cout << offsetof(S, a) << "\n"
              << offsetof(S, b) << "\n"
              << offsetof(S, c) << "\n\n";

    std::vector<int> v {0, 1, 2, 3, 4};

    auto pv = &v; // std::vector<int>* pv {&v};
    std::cout << pv << "\n";
    // Elements of a vector is placed in-order
    for (std::vector<int>::size_type i = 0; i < v.size(); ++i) {
        std::cout << &v[i] << "\n";
    }

    return 0;
}
