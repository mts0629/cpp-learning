#include <iostream>
#include <string>

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
            // Throw an exception from this function
            throw std::runtime_error("Not a number");
            break;
    }
}

int StringToInt(const std::string str) {
    int num = 0;
    for (const auto s : str) {
        // The exception is thrown from CharToInt()
        num = CharToInt(s);
    }
    return num;
}

// This function doesn't throw an exception explictly by "noexcept"
int Compare(int a, int b) noexcept {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    } else { // a == b
        return 0;
    }
}

// int Compare(int a, int b) noexcept(true);    // Throw an exception
// int CharToInt(const char c) noexcept(false); // Doesn't throw an exception

// noexcept if noexcept is specified at CharToInt()
// int StringToInt(const std::string& str) noexcept(noexcept(CharToInt(char())));

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

    try {
        throw 123; // Throw int
    } catch (const bool v) {
        std::cout << "bool" << std::endl;
    } catch (const int v) { // Be caught here by a type 'int' of the exception
        std::cout << "int" << std::endl;
    }

    try {
        // If a thrown exception is a class, upcasting is considered
        throw std::runtime_error("test");
    } catch (const std::exception& e) {
        // std::runtime_error is the derived class of std::exception,
        // therefore the exception is caught here
        std::cout << "std::exception: " << e.what() << std::endl;
    } catch (const std::runtime_error& e) {
        // This procedure doesn't be executed
        std::cout << "std::runtime_error: " << e.what() << std::endl;
    }

    try {
        throw 123;
    } catch (...) { // Any type of exceptions are caught
        // Exception object can't be refered
        std::cout << "Unexpected exception was thrown." << std::endl;
    }

    // Catch an exception thrown from a function
    try {
        // The exception is thrown from CharToInt() in StringToInt()
        auto num = StringToInt(str);
        std::cout << num << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    // If the thrown excpetion is not caught,
    // std::terminate will be called and the program will abort
    auto num = StringToInt(str);
    std::cout << num << std::endl;

    return 0;
}
