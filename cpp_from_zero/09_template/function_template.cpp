#include <iostream>

// Function template
// Data type T is decided at the compilation time
template <typename T>
T Sum(T a, T b) {
    return a + b;
}

// Using 2 template parameters
template <typename T, typename U>
// Inference type of return value from paramter types by "decltype"
auto Sum2(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Non-type template parameter
// Constant N is decided at the compilation time
template <int N>
int Fibonacchi() {
    int a[N + 1];

    a[0] = 0;
    a[1] = 1;
    for (auto i = 2; i <= N; ++i) {
        a[i] = a[i - 1] + a[i - 2];
    }

    return a[N];
}

int main() {
    // Call function templates
    std::cout << Sum<int>(1, 2) << std::endl;
    std::cout << Sum<double>(1.2, 3.4) << std::endl;

    // Type inference from parameters
    std::cout << Sum(1, 2) << std::endl;
    std::cout << Sum(1.2, 3.4) << std::endl;

    // For Sum(T a, T b), it causes complation error
    // std::cout << Sum(1, 2.3) << std::endl;

    // For Sum(T a, U b), a type inference works
    std::cout << Sum2(1, 2.3) << std::endl;

    // Specify non-type template parameter
    std::cout << Fibonacchi<10>() << std::endl;

    return 0;
}
