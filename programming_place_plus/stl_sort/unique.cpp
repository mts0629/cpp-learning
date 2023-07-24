#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {5, 6, -1, 3, 7, 2, 3};

    // Sort
    std::sort(std::begin(v), std::end(v));

    // Remove adjacent dupliated elements (not actually removed)
    auto it_end = std::unique(std::begin(v), std::end(v));

    for (auto it = std::cbegin(v); it != it_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
