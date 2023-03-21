#include <iostream>
#include <cstddef>
#include <array> // std::array
#include <string> // std::string
#include <tuple> // std::tuple
#include <utility> // std::pair
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

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

// Better
void PrintArray(const int* x, std::size_t num) {
    for (int i = 0; i < num; ++i) {
        std::cout << x[i] << std::endl;
    }
}

int main() {
    {
        // Array
        int x[5] = { 0, 1, 2, 3, 4 };
        int y = x[2]; // 2

        int x1[3]; // Declear with its size
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
    }

    {
        // String
        std::string s = "Hello";
        for (auto i = 0; i < s.size(); i++) {
            std::cout << s[i];
        }
        std::cout << std::endl;
    }

    {
        // Tuple
        std::tuple<std::string, int> person { "Bob", 20 };

        // No limitation for the number of elements
        std::tuple<std::string, int, std::string> person2 { "Bob", 20, "USA" };

        // Refer an element
        std::get<0>(person); // "Bob"
        std::get<1>(person); // 20

        // Initialization
        std::tuple<std::string, int> person3 { "Bob", 20 };
        std::tuple<std::string, int> person4("Bob", 20);
        std::tuple<std::string, int> person5 = std::make_tuple("Bob", 20);

        // Assign elements to variables with std::tie()
        std::string name;
        int age;
        std::string country;
        std::tie(name, age, country) = person2; // name = "Bob", age = 20, country = "USA"
    }

    {
        // Pair
        std::pair<std::string, int> person { "Bob", 20 };

        // Refer an element
        std::get<0>(person); // "Bob"
        std::get<1>(person); // 20
        person.first;  // "Bob"
        person.second; // 20

        // Initialization
        std::pair<std::string, int> person2 { "Bob", 20 };
        std::pair<std::string, int> person3("Bob", 20);
        std::pair<std::string, int> person4 = std::make_pair("Bob", 20);

        // Assignment with std::tie()
        std::string name;
        int age;
        std::tie(name, age) = person; // name = "Bob", age = 20
    }

    {
        // vector: dynamic array
        std::vector<int> x = { 0, 1, 2, 3, 4, 5 };
        x[2] = 10;

        // Get the size and scan elements
        for (auto i = 0; i < x.size(); ++i) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;

        // Push an element to the tail
        x.emplace_back(5);
        for (auto i = 0; i < x.size(); ++i) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;

        // Pop an element from the tail
        x.pop_back();
        for (auto i = 0; i < x.size(); ++i) {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;

        // Pointer access
        auto px = x.data();
        std::cout << *px << std::endl;
    }

    {
        // std::map: dictionary
        std::map<std::string, int> persons = {
            { "Alice", 18 },
            { "Bob", 20 }
        };

        // Refer with using keys
        std::cout << "persons[\"Alice\"] = " << persons["Alice"] << std::endl;
        std::cout << "persons[\"Bob\"] = " << persons["Bob"] << std::endl;

        // std::unordered_map
        // Using hash for data management, and an order of data does not be saved
        // Performance is better than that of std::map
        std::unordered_map<std::string, int> person_unordered = {
            { "Alice", 18 },
            { "Bob", 20 }
        };

        // Insert an element
        persons.insert({ "Eve", 19 });

        // Remove an element by a key
        persons.erase("Bob");
    }

    {
        // std::set: unique data container
        std::set<std::string> persons = {
            "Alice",
            "Bob"
        };

        // std::set
        // Same with std::unordered_map, using hash
        std::unordered_set<std::string> persons_unordrered = {
            "Alice",
            "Bob"
        };

        // Insert an element
        persons.insert("Eve");

        // Remove an element
        persons.erase("Bob");
    }

    {
        std::vector<int> x = { 0, 1, 2, 3, 4 };

        // Iterator
        auto it = x.begin();
        // Can use like as a pointer
        std::cout << *it << std::endl;
        ++it;
        std::cout << *it << std::endl;

        // Loop with iterator
        // x.end() is the next one of the last element of x
        for (auto it = x.begin(); it != x.end(); ++it) {
            std::cout << *it << std::endl;
        }

        // Does not depend on the type of STL containers
        std::vector<int> y = { 0, 1, 2, 3, 4 };
        for (auto it = y.begin(); it != y.end(); ++it) {
            std::cout << *it << std::endl;
        }

        // Functions in <algorithm> can be used via iterator
        auto n = std::count_if(x.begin(), x.end(), [](const int v) {
            if (v <= 0) {
                return false;
            }
            if (v %2 != 0) {
                return false;
            }
            return true;
        });
        std::cout << n << std::endl; // 2

        // An iterator for std::map, std::unordered_map are std::pair
        std::map<std::string, int> persons = {
            { "Alice", 18 },
            { "Bob", 20 }
        };

        for (auto it = persons.begin(); it != persons.end(); ++it) {
            const auto& person = *it; // std::pair<std::string, int>
            const std::string& name = person.first;
            const int age = person.second;
            std::cout << name << ": " << age << std::endl;
        }

        // Forward iterator
        std::unordered_set<int> us = { 0, 1, 2, 3, 4, 5 };
        for (auto it = us.begin(); it != us.end(); ++it) {
            std::cout << *it << std::endl;
        }

        // Bidirectional iterator
        std::set<int> s = { 0, 1, 2, 3, 4, 5 };
        for (auto it = s.begin(); it != s.end(); ++it) {
            std::cout << *it << std::endl;
        }
        for (auto it = --(s.end()); it != s.begin(); --it) {
            std::cout << *it << std::endl;
        }

        // Random access iterator
        auto itr = x.begin();
        itr = itr + 3;
        std::cout << *itr << std::endl; // 3
        std::cout << itr[-2] << std::endl; // 1
        std::cout << *itr << std::endl; // 3, iterator was not changed

        auto it1 = x.begin() + 2; // 2
        auto it2 = x.begin() + 3; // 3
        auto it3 = x.begin() + 4; // 4

        x.erase(x.begin() + 3);

        // Iterator will be invalid
        std::cout << *it1 << std::endl; // 2
        // std::cout << *it2 << std::endl; // Undefined behavior
        // std::cout << *it3 << std::endl; // Undefined behavior
    }

    {
        // Range-based for statement
        std::vector<int> x = { 0, 1, 2, 3, 4, 5 };
        for (auto&& e : x) {
            std::cout << e << std::endl;
        }

        // For an array
        int y[] = { 0, 1, 2, 3, 4, 5 };
        for (auto&& e : y) {
            std::cout << e << std::endl;
        }
    }

    return 0;
}
