#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {5, 16, -10, 0, -5, 10};

    auto it = std::max_element(std::cbegin(v), std::cend(v));
    std::cout << *it << std::endl;

    it = std::min_element(std::cbegin(v), std::cend(v));
    std::cout << *it << std::endl;

    return 0;
}
