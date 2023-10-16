#include <iostream>
#include <string> // std::string

int main() {
    // String
    std::string s = "Hello";
    for (auto i = 0; i < s.size(); ++i) {
        std::cout << s[i];
    }
    std::cout << std::endl;

    return 0;
}
