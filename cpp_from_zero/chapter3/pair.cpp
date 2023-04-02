#include <iostream>
#include <string>
#include <tuple> // std::tie
#include <utility> // std::pair

int main() {
    // Pair
    std::pair<std::string, int> person { "Bob", 20 };

    // Refer an element
    std::get<0>(person); // "Bob"
    std::get<1>(person); // 20
    std::cout << person.first << ", "   // "Bob"
              << person.second          // 20
              << std::endl;

    // Initialization
    std::pair<std::string, int> person2 { "Bob", 20 };
    std::pair<std::string, int> person3("Bob", 20);
    std::pair<std::string, int> person4 = std::make_pair("Bob", 20);

    // Assignment with std::tie()
    std::string name;
    int age;
    std::tie(name, age) = person; // name = "Bob", age = 20

    std::cout << name << ", " << age << std::endl;

    return 0;
}
