#include <algorithm> // std::count_if
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> x = { 0, 1, 2, 3, 4 };

    // Iterator
    auto it = x.begin();
    // Can use like as a pointer
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;

    // Loop with iterator
    // x.end() is the next one of the last element of x
    for (auto it = x.begin(); it != x.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Does not depend on the type of STL containers
    std::vector<int> y = { 0, 1, 2, 3, 4 };
    for (auto it = y.begin(); it != y.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Functions in <algorithm> can be used via iterator
    auto n = std::count_if(x.begin(), x.end(), [](const int v) {
        if (v <= 0) {
            return false;
        }
        if (v %2 != 0) {
            return false;
        }
        return true;
    });
    std::cout << n << std::endl; // 2

    // An iterator for std::map, std::unordered_map are std::pair
    std::map<std::string, int> persons = {
        { "Alice", 18 },
        { "Bob", 20 }
    };

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        const auto& person = *it; // std::pair<std::string, int>
        const std::string& name = person.first;
        const int age = person.second;
        std::cout << name << ": " << age << std::endl;
    }

    // Forward iterator
    std::unordered_set<int> us = { 0, 1, 2, 3, 4, 5 };
    for (auto it = us.begin(); it != us.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // Bidirectional iterator
    std::set<int> s = { 0, 1, 2, 3, 4, 5 };
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (auto it = --(s.end()); it != s.begin(); --it) {
        std::cout << *it << std::endl;
    }

    // Random access iterator
    auto itr = x.begin();
    itr = itr + 3;
    std::cout << *itr << std::endl; // 3
    std::cout << itr[-2] << std::endl; // 1
    std::cout << *itr << std::endl; // 3, iterator was not changed

    auto it1 = x.begin() + 2; // 2
    auto it2 = x.begin() + 3; // 3
    auto it3 = x.begin() + 4; // 4

    x.erase(x.begin() + 3); // Index will be changed

    std::cout << *it1 << std::endl; // 2
    // std::cout << *it2 << std::endl; // Undefined behavior
    // std::cout << *it3 << std::endl; // Undefined behavior

    return 0;
}
