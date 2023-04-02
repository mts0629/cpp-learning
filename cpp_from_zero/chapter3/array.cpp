#include <array> // std::array
#include <iostream>

// Function template: get the number of elements of an array
template <class T, std::size_t N>
constexpr std::size_t size(const T (&)[N]) noexcept { return N; }

void PrintArray1(const int x[5]) {
    // static_assert(sizeof(x) == sizeof(int*), "");
    for (int i = 0; i < 5; ++i) {
        std::cout << x[i] << std::endl;
    }
}

// Same with PrintArray1()
void PrintArray2(const int* x) {
    for (int i = 0; i < 5; ++i) {
        std::cout << x[i] << std::endl;
    }
}

// Better way: get the size by argument
void PrintArray(const int* x, std::size_t num) {
    for (int i = 0; i < num; ++i) {
        std::cout << x[i] << std::endl;
    }
}

int main() {
    // Array
    int x[5] = { 0, 1, 2, 3, 4 };
    int y = x[2]; // 2

    // Declear an array with the size
    int x1[3];
    x1[0] = 0;
    x1[1] = 1;
    x1[2] = 2;

    int x2[5] = { 0, 1, 2 }; // x[3] = x[4] = 0

    int x3[5] = { }; // All 0

    // Implicit type casting to pointer-type
    int* p = x;
    std::cout << *p << std::endl;
    std::cout << *(p + 1) << std::endl;
    std::cout << *(p + 2) << std::endl;
    std::cout << *(p + 3) << std::endl;
    std::cout << *(p + 4) << std::endl;

    // A pointer to the first element of the array is passed
    PrintArray1(x);
    PrintArray2(x);
    // Therefore the number of elements is required basically
    // std::size can be used from C++17
    PrintArray(x, size(x));

    // STL array by <array>
    std::array<int, 5> stdx = { 0, 1, 2, 3, 4 }; // From C++14
    // std::array<int, 5> stdx = {{ 0, 1, 2, 3, 4 }}; // Before

    auto stdx_size = stdx.size();
    // auto stdx_size = std::size(stdx); // From C++17

    int arr1_1[3] = {};
    // int arr1_2[3] = arr1_1; // Compilation error
    std::array<int, 3> arr2_1;
    std::array<int, 3> arr2_2 = arr2_1; // Copy

    return 0;
}
