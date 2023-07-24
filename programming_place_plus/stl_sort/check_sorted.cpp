#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {5, 6, -1, 3, 7, 2, 3};

    // Check whether the colllection is sorted or not by the condition (passed by the third argument)
    std::cout << std::boolalpha << std::is_sorted(std::cbegin(v), std::cend(v)) << std::endl;
    std::sort(std::begin(v), std::end(v));
    std::cout << std::boolalpha << std::is_sorted(std::cbegin(v), std::cend(v)) << std::endl;

    std::cout << std::boolalpha << std::is_sorted(std::cbegin(v), std::cend(v), std::greater<int>{}) << std::endl;
    std::sort(std::begin(v), std::end(v), std::greater<int>{});
    std::cout << std::boolalpha << std::is_sorted(std::cbegin(v), std::cend(v), std::greater<int>{}) << std::endl;

    return 0;
}
