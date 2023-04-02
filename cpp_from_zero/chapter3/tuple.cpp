#include <iostream>
#include <string>
#include <tuple>

int main() {
    // Tuple
    std::tuple<std::string, int> person { "Bob", 20 };

    // No limitation for the number of elements
    std::tuple<std::string, int, std::string> person2 { "Bob", 20, "USA" };

    // Refer an element
    std::cout << std::get<0>(person) << ", "    // "Bob"
              << std::get<1>(person)            // 20
              << std::endl;

    // Initialization
    std::tuple<std::string, int> person3 { "Bob", 20 };
    std::tuple<std::string, int> person4("Bob", 20);
    std::tuple<std::string, int> person5 = std::make_tuple("Bob", 20);

    // Assign elements to variables with std::tie()
    std::string name;
    int age;
    std::string country;
    std::tie(name, age, country) = person2; // name = "Bob", age = 20, country = "USA"

    std::cout << name << ", " << age << ", " << country << std::endl;

    return 0;
}
