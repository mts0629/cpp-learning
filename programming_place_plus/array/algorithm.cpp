#include <algorithm>
#include <cstring>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    constexpr std::size_t array_size {5};
    int array1[array_size] {1, 2, 3, 4, 5};
    int array2[array_size] {};

    // Copy the array
    std::copy(std::cbegin(array1), std::cend(array1), std::begin(array2));

    for (auto i = 0; i < array_size; ++i) {
        std::cout << array1[i] << "," << array2[i] << "\n";
    }
    std::cout << "\n";

    // Copy the array by its size
    std::copy_n(std::cbegin(array1), array_size, std::begin(array2));

    for (auto i = 0; i < array_size; ++i) {
        std::cout << array1[i] << "," << array2[i] << "\n";
    }
    std::cout << "\n";

    // Fill the array
    std::fill(std::begin(array1), std::end(array1), 0);

    for (auto& e: array1) {
        std::cout << e << "\n";
    }
    std::cout << "\n";

    // Fill the array by its size
    std::fill_n(std::begin(array1), array_size, 0);

    for (auto& e: array1) {
        std::cout << e << "\n";
    }
    std::cout << "\n";

    int array3[] {1, 2 , 3, 4, 5};

    std::cout << std::boolalpha
              // Compare two arrays for each element
              << std::equal(std::cbegin(array1), std::cend(array1),
                            std::cbegin(array2), std::cend(array2)) << "\n"
              << std::equal(std::cbegin(array2), std::cend(array2),
                            std::cbegin(array3), std::cend(array3)) << "\n\n";

    std::vector<int> vec {1, 2, 3, 4, 5};
    int array[] {1, 2, 3, 4, 5};

    // vec = array; // Compilation error
    // array = vec; // Compilation error

    // Compare by the iterator
    if (std::equal(std::cbegin(vec), std::cend(vec),
                   std::cbegin(array), std::cend(array))) {
        std::cout << "match" << "\n";
    }

    // Copy by the iterator
    std::copy(std::cbegin(array), std::cend(array), std::begin(vec));
    std::copy(std::cbegin(vec), std::cend(vec), std::begin(array));

    // Create a new vector from the array
    std::vector<int> copy_array(std::cbegin(array), std::cend(array));

    // Create a new array from the vector
    int vec_copy[5] {}; // Need to declare
    std::copy(std::cbegin(vec), std::cend(vec), std::begin(vec_copy));

    return 0;
}
