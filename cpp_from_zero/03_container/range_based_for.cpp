#include <iostream>
#include <vector>

int main() {
    // Range-based for statement
    std::vector<int> x = { 0, 1, 2, 3, 4, 5 };
    for (auto&& e : x) {
        std::cout << e << std::endl;
    }

    // For an array
    int y[] = { 0, 1, 2, 3, 4, 5 };
    for (auto&& e : y) {
        std::cout << e << std::endl;
    }

    return 0;
}
