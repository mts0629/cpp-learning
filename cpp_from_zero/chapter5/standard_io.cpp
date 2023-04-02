#include <iostream>

int main() {
    // Standard output
    std::cout << "Standard output" << std::endl;

    // Standard error output
    std::cerr << "Standard error output" << std::endl;

    std::cout << "Input your favorite food: ";
    std::string food;
    // Standard input
    std::cin >> food;
    std::cout << "Your favorite food is: " << food << std::endl;

    int x = 0;
    std::cout << "Input an integer: ";
    // Check a result of input
    if (std::cin >> x) {
        std::cout << "Input is: " << x << std::endl;
    } else {
        std::cout << "Your input is invalid" << std::endl;
    }

    return 0;
}
