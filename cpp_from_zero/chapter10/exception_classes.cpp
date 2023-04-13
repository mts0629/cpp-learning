#include <bitset>
#include <iostream>
#include <string>
#include <vector>

int CharToInt(const char c) {
    switch (c) {
        case '0': return 0; break;
        case '1': return 1; break;
        case '2': return 2; break;
        case '3': return 3; break;
        case '4': return 4; break;
        case '5': return 5; break;
        case '6': return 6; break;
        case '7': return 7; break;
        case '8': return 8; break;
        case '9': return 9; break;
        default:
            throw std::runtime_error("Not a number");
            break;
    }
}

int StringToInt(const std::string str) {
    int num = 0;
    for (const auto s : str) {
        num = CharToInt(s);
    }
    return num;
}

int main() {
    std::string str = "123XY56";

    // std::exception: the base class of exception classes in standard library
    try {
        auto num = StringToInt(str);
        std::cout << num << std::endl;
    } catch (const std::exception& e) { // Any type of exceptions can be caught
        std::cout << e.what() << std::endl;
    }

    // std::logic_error: an error like lack of prerequisites
    // there are no functions throw std::logic_error in standard library

    // std::invalld_argument: an error like an argument of the function is invalid
    try {
        std::bitset<8> b("0000x111"); // Invalid character 'x' is included
        std::cout << b << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "std::invalid_argument is caught" << std::endl;
        std::cout << e.what() << std::endl;
    }

    // std::out_of_range: an error like an element outside the range of an array is refered
    std::vector<int> x = {1, 2, 3, 4, 5};
    try {
        int a = x.at(5);
        std::cout << "The fifth value: " << a << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "std::out_of_range is caught" << std::endl;
        std::cout << e.what() << std::endl;
    }

    // Reference with [] doesn't throw an exception
    try {
        int a = x[5]; // Sometime the segmentation fault occurs
        std::cout << "The fifth value: " << a << std::endl; // Unstable
    } catch (...) {
        std::cout << "An exception is caught" << std::endl;
    }

    // std::runtime_error: an error like a problem in the execution environment

    // std::bad_cast: failure of dynamic_cast

    return 0;
}
