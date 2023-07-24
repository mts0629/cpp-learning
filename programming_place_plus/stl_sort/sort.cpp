#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Name {
    std::string family_name;
    std::string first_name;
};

int main() {
    std::vector<int> v = {5, 6, -1, 3, 7, 2, 3};

    // Sort by ascending order
    std::sort(std::begin(v), std::end(v));

    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // Sort by descending order
    std::sort(std::begin(v), std::end(v), [](int a, int b){ return a > b; });
    // Same operation with defined function object class
    // std::sort(std::begin(v), std::end(v), std::greater<int>{});

    for (auto e : v) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::vector<Name> names = {
        {"Saitou", "Ken"},
        {"Yoshida", "Emiko"},
        {"Saitou", "Yuuko"},
        {"Saitou", "Akihisa"},
        {"Nakamura", "Hideo"},
    };

    // Sort by two keys with lambda expression
    std::sort(std::begin(names), std::end(names),
        [](const Name& a, const Name& b) {
            if (a.family_name == b.family_name) {
                // Secondary key: first_name
                return a.first_name < b.first_name;
            }
            // Primary key: family_name
            return a.family_name < b.family_name;
        }
    );

    for (auto e : names) {
        std::cout << e.family_name << " " << e.first_name << std::endl;
    }

    return 0;
}
