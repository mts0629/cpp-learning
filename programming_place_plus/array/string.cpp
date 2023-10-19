#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

int main() {
    char s1[5] = {'a', 'b', 'c', 'd'};
    char s2[5] {'a', 'b', 'c', 'd'};
    char s3[] = {'a', 'b', 'c', 'd'};
    char s4[] {'a', 'b', 'c', 'd'};
    char s5[] = "abcd"; // const char[5]
    char s6[10] = "abcd";
    char s7[5];
    char s8[5] {};
    // char s9[5] = "abcde"; // Compilation error

    std::cout << s1 << "\n";
    std::cout << "size=" << std::strlen(s1) << "\n\n"; // Size of NULL-terminated string

    char s9[] = "abc";
    char s10[] = "abcde";

    // Compare two NULL-terminated strings
    std::cout << std::strcmp(s9, s10) << "\n" // < 0 when first < second
              << std::strcmp(s10, s9) << "\n" // < 0 when first > second
              << std::strcmp(s9, "abc") << "\n\n"; // 0 when first == second

    // std::string can be compared with an array of char
    std::string s = "abcde";
    std::cout << std::boolalpha
              << (s == s9) << "\n"
              << (s == s10) << "\n";

    // Copy by the iterator
    std::copy(std::cbegin(s9), std::cbegin(s9), std::begin(s10));

    return 0;
}
