#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4 };

    // Find the first element
    auto it = std::find(std::cbegin(v), std::cend(v), 3);   // std::cbegin and std::cend
                                                            // return const iterators
    if (it != std::cend(v)) {
        std::cout << "found: " << *it << std::endl;
    }

    // Find the first element specified by the condition
    it = std::find_if(std::cbegin(v), std::cend(v), [](int e){ return e % 2 == 1; });
    if (it != std::cend(v)) {
        std::cout << "found: " << *it << std::endl;
    }

    // Search by negative condition
    it = std::find_if_not(std::cbegin(v), std::cend(v), [](int e){ return e % 2 == 1; });
    if (it != std::cend(v)) {
        std::cout << "found: " << *it << std::endl;
    }

    return 0;
}
