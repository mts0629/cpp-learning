#include <iostream>
#include <set> // std::set
#include <unordered_set> // std::unordered_set

int main() {
    // std::set: unique data container
    std::set<std::string> persons = {
        "Alice",
        "Bob"
    };

    // Access with an iterator
    for (auto it = persons.begin(); it != persons.end(); ++it) {
        std:: cout << *it << std::endl;
    }

    // std::unordered_set
    // Same with std::unordered_map, using hash for data storing
    std::unordered_set<std::string> persons_unordrered = {
        "Alice",
        "Bob"
    };

    // Insert an element
    persons.insert("Eve");

    // Remove an element
    persons.erase("Bob");

    for (auto it = persons.begin(); it != persons.end(); ++it) {
        std:: cout << *it << std::endl;
    }

    return 0;
}
