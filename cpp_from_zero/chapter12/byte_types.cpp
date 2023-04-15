#include <climits>
#include <iostream>

void Hoge(char c) {
    std::cout << "char: " << c << std::endl;
}

void Hoge(signed char c) {
    std::cout << "signed char: " << c << std::endl;
}

void Hoge(unsigned char c) {
    std::cout << "unsigned char: " << c << std::endl;
}

int main() {
    // Data type with 1 byte: char, signed char, unsigned char
    // These are thought as different type
    Hoge('A');
    Hoge(static_cast<char>('B'));
    Hoge(static_cast<signed char>('C'));
    Hoge(static_cast<unsigned char>('D'));

    // std::byte can be used from C++17

    // The size of char is 8bit at least and it is defined with CHAR_BIT
    static_assert(CHAR_BIT == 8, "Not support 1byte != 8bits");

    return 0;
}
