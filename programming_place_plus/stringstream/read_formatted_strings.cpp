#include <iostream>
#include <sstream>
#include <string>

int main() {
    int value1 = 0;
    std::string op = "";
    int value2 = 0;

    // Parse "12 + 16"
    std::istringstream iss {"12 + 16"};
    iss >> value1 >> op >> value2;
    std::cout << value1 << " " << op << " " << value2 << std::endl;

    // Clear an internal state
    iss.clear();

    // Parse "7 / 2"
    iss.str("7 / 2"); // Set a new string
    iss >> value1 >> op >> value2;
    std::cout << value1 << " " << op << " " << value2 << std::endl;

    return 0;
}
