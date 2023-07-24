#include <fstream>
#include <iostream>
#ifdef _WIN32
// For stdout on Windows
#define NOMINMAX // Deactivate min/max macro
#include <Windows.h>
#endif

int main() {
    std::ofstream ofs("test.txt");
    // UTF-8 string literal
    ofs << u8"あいうえお\n";

#ifdef __cpp_char8_t
    // For C++20
    // UTF-8 literals are typed to char8_t
    // and it cannot be output with std::cout directly
    // const char8_t*
    auto u8chars = u8"あいうえお";
    std::cout << reinterpret_cast<const char*>(u8chars) << std::endl;

    // std::u8string
    std::u8string u8str = u8"かきくけこ";
    std::cout << reinterpret_cast<const char*>(u8str.c_str()) << std::endl;

    // char8_t: "C0 Controls and Basic Latin Unicode block"
    char8_t u8char = u8'A';
    std::cout << static_cast<char>(u8char) << std::endl;
#else
#ifdef _WIN32
    // Set code page to UTF-8 (CP932 in default)
    SetConsoleOutputCP(CP_UTF8);
#endif
    // Output to stdout
    std::cout << u8"あいうえお\n";
    std::cout << u8"😎\n"; // Emoji
#endif

    return 0;
}
