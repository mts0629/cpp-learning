#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

int main() {
    std::string s = "BaAb";

    // Sort by the order of ASCII code: capitals are smaller
    std::sort(std::begin(s), std::end(s));

    std::cout << s << std::endl;

    s.clear();
    s = "BaAb";

    // Sort by ignoring capital/small letter
    // and make the small letter precedes to the capital
    std::sort(std::begin(s), std::end(s),
        [](char a, char b) {
            // Convert to the capital
            auto upper_a = std::toupper(a);
            auto upper_b = std::toupper(b);

            // Compare
            // If a and b is the same letter, sort in descending order
            if (upper_a == upper_b) {
                return a > b;
            }
            return upper_a < upper_b;
        }
    );

    std::cout << s << std::endl;

    return 0;
}
