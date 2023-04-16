#include <iostream>
#include <vector> // std::vector

int main() {
    // vector: dynamic array
    std::vector<int> x = { 0, 1, 2, 3, 4, 5 };
    x[2] = 10;

    // Get the size and scan elements
    for (auto i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    // Append an element to the tail
    x.emplace_back(5);
    for (auto i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    // Remove an element from the tail
    x.pop_back();
    for (auto i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    // Pointer access
    auto px = x.data();
    std::cout << *px << std::endl;

    return 0;
}
