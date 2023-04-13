#include <iostream>
#include <string>

int main() {
    std::string str = "123XY56";

    // Exception handling
    // try - catch block
    try {
        int num = 0;
        // Convert string to number
        for (const auto s : str) {
            num *= 10;
            switch (s) {
                case '0': num += 0; break;
                case '1': num += 1; break;
                case '2': num += 2; break;
                case '3': num += 3; break;
                case '4': num += 4; break;
                case '5': num += 5; break;
                case '6': num += 6; break;
                case '7': num += 7; break;
                case '8': num += 8; break;
                case '9': num += 9; break;
                default:
                    // Throw an exception
                    // Set an error message by an argument of the constructor
                    throw std::runtime_error("Not a number");
                    break;
            }
        }
        // Display the converted value
        std::cout << num << std::endl;
    } catch (const std::runtime_error& e) {
        // Catch the exception
        // Get an error message with what()
        std::cout << e.what() << std::endl;
    }

    return 0;
}
