#include <iostream>
#include <sstream>
#include <string>

int main() {
    // Opertors
    constexpr auto addition = '+';
    constexpr auto subtraction = '-';
    constexpr auto multiplication = '*';
    constexpr auto division = '/';

    while (true) {
        std::cout << "Please enter the formula." << std::endl;

        std::string input_string = {};
        std::getline(std::cin, input_string);

        // If "exit" is input, exit the main loop
        if (input_string == "exit") {
            break;
        }

        // Input string stream
        std::istringstream iss {input_string};

        // Parse the stream into:
        // <value1> <operator> <value2>
        int value1 = 0;
        std::string op = "";
        int value2 = 0;
        iss >> value1 >> op >> value2;

        // Calculate and output a result by the operator
        switch (op[0]) {
            case addition:
                std::cout << value1 + value2 << std::endl;
                break;
            case subtraction:
                std::cout << value1 - value2 << std::endl;
                break;
            case multiplication:
                std::cout << value1 * value2 << std::endl;
                break;
            case division:
                std::cout << value1 / value2 << std::endl;
                break;
            default:
                std::cout << "The formula is incorrect." << std::endl;
                break;
        }
    }
 
    return 0;
}
