#include <iostream>
#include <sstream>
#include <string>

int main() {
    int n1 = 123;
    int n2 = 999;

    // Output string stream
    std::ostringstream oss {};
    oss << n1 << "abc" << n2;

    // Get a string object
    std::string s {oss.str()};
    std::cout << s << std::endl; // or std::cout << oss.str() << std::endl;

    // Clear the string object
    oss.str("");

    int n3 = 1024;
    oss << n1 << "abc" << n3;
    std::cout << oss.str() << std::endl;

    return 0;
}
