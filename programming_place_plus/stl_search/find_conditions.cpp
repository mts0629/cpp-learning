#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {102, 99, 100, 101, 103};

    // Condition by logical OR
    auto it = std::find_if(std::cbegin(v), std::cend(v),
        [](int e){ return (e >= 100) || (e % 5 == 0); }
    );
    if (it != std::cend(v)) {
        std::cout << "found: " << *it << std::endl;
    }

    // Condition by logical AND
    it = std::find_if(std::cbegin(v), std::cend(v),
        [](int e){ return (e >= 100) && (e % 2 != 0); }
    );
    if (it != std::cend(v)) {
        std::cout << "found: " << *it << std::endl;
    }

    // Condition by logical NOT
    std::vector<std::string> v_str = {"", "", "hello"};
    auto it_str = std::find_if(std::cbegin(v_str), std::cend(v_str),
        [](std::string e){ return !e.empty(); }
    );
    if (it_str != std::cend(v_str)) {
        std::cout << "found: " << *it_str << std::endl;
    }

    return 0;
}
