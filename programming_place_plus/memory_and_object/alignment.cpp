#include <iostream>

int main() {
    struct S {
        long long a; // 8 byte
        char b;      // 1 byte
                     // (1 byte padding)
        short c;     // 2 byte
                     // (4 byte padding)
    };               // -> 16 bytes in total

    // Data alignment
    std::cout << "char: " << alignof(char) << "\n"
              << "short: " << alignof(short) << "\n"
              << "int: " << alignof(int) << "\n"
              << "long: " << alignof(long) << "\n"
              << "long long: " << alignof(long long) << "\n"
              << "S: " << alignof(S) << "\n\n";

    // Alignment specifier
    struct alignas(16) S1 {
        int a;
        short b;
    };

    struct S2 {
        alignas(8) int a;
        short b;
    };

    enum class alignas(16) E {
        e1,
        e2,
        e3,
    };

    alignas(8) int a {};
    alignas(S1) short b {}; // alignas(alignof(S1))

    std::cout << alignof(S1) << "\n" // 16
              << alignof(S2) << "\n" // 8
              << alignof(E) << "\n"; // 16

    return 0;
}
