#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4 };

    // Count all specified elements
    auto count = std::count(std::cbegin(v), std::cend(v), 2);
    std::cout << count << std::endl;

    // Count all specified elements by the condition
    count = std::count_if(std::cbegin(v), std::cend(v), [](int e){ return e % 2 == 1; });
    std::cout << count << std::endl;

    // Apply the given function to all elements
    std::transform(std::begin(v), std::end(v),
        std::begin(v), [](int e){ return (e % 2 == 0) ? (e * 2) : e; }
    );
    for (auto e : v) {
        std::cout << e << ",";
    }
    std::cout << std::endl;

    // Remove all of the specified elements by the condition
    v.erase(
        std::remove_if(std::begin(v), std::end(v), [](int e){ return e % 4 == 0; })
    );
    for (auto e : v) {
        std::cout << e << ",";
    }
    std::cout << std::endl;

    return 0;
}
