#include <iostream>
#include <map> // std::map
#include <string>
#include <unordered_map> // std::unordered_map

int main() {
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

    return 0;
}
