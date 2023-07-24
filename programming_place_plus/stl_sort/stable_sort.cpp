#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using int_pair = std::pair<int, int>;

int main() {
    std::vector<int_pair> numbers = {
        {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7},
        {5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6},
        {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5},
        {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4},
        {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3},
        {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2},
        {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1},
    };

    // Unstable sort
    std::sort(std::begin(numbers), std::end(numbers),
        [](const int_pair& a, const int_pair& b) {
            return a.first < b.first;
        }
    );

    // The order of std::pair.second is not reserved
    for (auto e : numbers) {
        std::cout << e.first << " " << e.second << std::endl;
    }

    numbers.clear();

    std::cout << "-----" << std::endl;

    numbers = {
        {5, 7}, {4, 7}, {3, 7}, {2, 7}, {1, 7},
        {5, 6}, {4, 6}, {3, 6}, {2, 6}, {1, 6},
        {5, 5}, {4, 5}, {3, 5}, {2, 5}, {1, 5},
        {5, 4}, {4, 4}, {3, 4}, {2, 4}, {1, 4},
        {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3},
        {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2},
        {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1},
    };

    // Stable sort
    std::stable_sort(std::begin(numbers), std::end(numbers),
        [](const int_pair& a, const int_pair& b) {
            return a.first < b.first;
        }
    );

    // The order of std::pair.second is reserved
    for (auto e : numbers) {
        std::cout << e.first << " " << e.second << std::endl;
    }

    return 0;
}
