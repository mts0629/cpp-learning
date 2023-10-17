#include <iostream>
#include <string>
#include <vector>

// struct
struct Book {
    std::string title {}; // Initializer
    std::string author {};
    int price {};
    int evaluate {5};
};

// struct is aggregate when ...
// - no protected/private members
// - no static members
// - no base class
// - no virtual functions
// - no user-defined constructors

int main() {
    // title="", author="", price=0, evaluate=5
    Book book1 {};

    // Aggregate initialization
    // title="C++ Programming Guide Book", author="Thomas Murray",
    // price=3500, evaluate=5
    Book book2 {"C++ Programming Guide Book", "Thomas Murray", 3500, 5};

    std::cout << book2.title << std::endl;
    std::cout << book2.author << std::endl;
    std::cout << book2.price << std::endl;
    std::cout << book2.evaluate << std::endl;

    Book book3 = book2;

    // Comparison
    std::cout << std::boolalpha
              << (book2.title == book3.title &&
                  book2.author == book3.author &&
                  book2.price == book3.price &&
                  book2.evaluate == book3.evaluate)
              << std::endl;

    std::vector<Book> books {book2};
    Book book4;
    // Aggregate can be assigned values with the initializer list
    book4 = {"C++ Programming Primer", "Sonia Elis", 2200, 3};
    books.push_back(book4);
    // Also push_back() can use initialize list
    books.push_back({"C++ Tutorial", "Jack Simon", 2800, 4});

    // for (auto book : books) { // Data members are copied
    for (const auto& book : books) { // Only a reference is copied
        std::cout << book.title << "\n"
                  << book.author << "\n"
                  << book.price << "\n"
                  << book.evaluate << std::endl;
    }

    return 0;
}
