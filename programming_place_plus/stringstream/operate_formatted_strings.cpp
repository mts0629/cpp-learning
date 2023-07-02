#include <iostream>
#include <sstream>
#include <string>

int main() {
    // String stream
    std::stringstream ss {"30 + 50"};

    int value1 = 0;
    std::string op = "";
    int value2 = 0;

    // Parse a formatted string
    ss >> value1 >> op >> value2;

    std::cout << value1 << " " << op << " " << value2 << std::endl;

    // Reset the stream
    ss.clear();
    ss.str("");

    // Construct a formatted string
    ss << 5 << " * " << 2;
    std::cout << ss.str() << std::endl;

    return 0;
}
