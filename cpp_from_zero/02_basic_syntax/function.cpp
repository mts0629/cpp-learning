#include <iostream>
#include <functional>

// Forward declaration
void HelloWorld(int n);

// Function
void HelloWorld(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "[" << i << "] " << "Hello world!" << std::endl;
    }
}

// Function overload
void Print(int x) {
    std::cout << "int: " << x << std::endl;
}

void Print(double x) {
    std::cout << "double: " << x << std::endl;
}

int Add(int x, int y) {
    return x + y;
}

int main(int argc, char* argv[]) {
    // Call function
    HelloWorld(10);

    // Display commandline arguments
    for (int i = 0; i < argc; ++i) {
        std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
    }

    // A callee is changed by the type of an argument
    Print(2);
    Print(2.1);

    // Function pointer
    // for a function which returns integer and get 2 integer arguments
    int (*fp)(int, int) = Add;
    int result = fp(3, 5);
    std::cout << result << std::endl;

    // Type inference can be used
    auto auto_fp = Add;

    // Lambda expression
    // A function which returns integer and get 2 integer arguments
    auto func = [](int a, int b) -> int { return a + b; };

    result = func(4, 6);
    std::cout << result << std::endl;

    int init = 5;

    // Outer variables can be used by lambda introducer "[]"
    // Copy capture: copied "init" is used
    auto f = [init](int a, int b) { return init + a * b; };
    // Reference capture: a reference of "init" is used
    auto g = [&init](int a, int b) { return init + a * b; };

    init = 0;

    int result_copy = f(2, 4); // init = 5
    std::cout << result_copy << std::endl;

    int result_ref = g(2, 4); // init = 0
    std::cout << result_ref << std::endl;

    auto func1 = []() -> int { return 400; }; // Omit argument
    auto func2 = []() { return 400; }; // Omit argument and return type
    auto func3 = [](int a, int b) { return a + b; };  // Return type is inferenced (int + int = int)

    // Implicit casting for function pointer when capture is not used
    int (*lamdda_fp)(int, int) = [](int x, int y) { return x + y; };

    // std::function by <functional>
    std::function<int(int, int)> stdf = Add;
    result = stdf(3, 5);
    std::cout << result << std::endl;

    stdf = [](int x, int y) { return x * y; }; // Also lambda expression can be used
    std::cout << stdf(4, 7) << std::endl;

    return 0;
}
