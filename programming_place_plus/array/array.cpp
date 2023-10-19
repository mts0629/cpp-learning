#include <iostream>

int main() {
    // Array initialization
    int a1[5] = {4, 6, 2, 5, 3};
    int a2[5] {4, 6, 2, 5, 3};
    int a3[] = {10, 20, 30}; // 3 elements
    int a4[] {10, 20, 30};   // 3 elements
    int a5[5]; // Uninitialized
    int a6[10] {}; // Initialized with 0
    // int a7[3] = a4; // Compilation error
    int v1 {10}, v2 {20};
    // int& a7[] {v1, v2}; // COmpilation error

    // Access by the index
    for (auto i = 0; i < 3; ++i) {
        std::cout << a3[i] << "\n";
    }

    // Access by the range-based for
    for (auto e: a3) {
        std::cout << e << "\n";
    }

    // Access by the iterator
    for (auto it = std::cbegin(a3); it != std::cend(a3); ++it) {
        std::cout << *it << "\n";
    }
    std::cout << "\n";

    auto it = std::cbegin(a3);
    std::cout << *it << std::endl;
    it += 2;
    std::cout << *it << std::endl;

    // The number of elements
    auto size = sizeof(a3) / sizeof(a3[0]);
    std::cout << "size=" << size << "\n";

    return 0;
}
