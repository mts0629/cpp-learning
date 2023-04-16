#include <climits>
#include <cstdint>
#include <cstring>
#include <iostream>

static_assert(CHAR_BIT == 8, "Not support 1 byte != 8 bits");

struct FundamentalTypes {
    int16_t i;
    double d;
};

int main() {
    FundamentalTypes f;

    // Set all bits to 0
    std::memset(&f, 0, sizeof(f));
    std::cout << f.i << std::endl;
    std::cout << f.d << std::endl;

    // Set all bits to 1
    std::memset(&f, 0xff, sizeof(f));
    std::cout << f.i << std::endl;
    std::cout << f.d << std::endl;

    FundamentalTypes f1;
    f1.i = -2;
    f1.d = 2.71;

    // Copy byte sequence
    FundamentalTypes f2;
    std::memcpy(&f2, &f1, sizeof(FundamentalTypes));
    std::cout << f.i << std::endl;
    std::cout << f.d << std::endl;

    FundamentalTypes f3;
    f3.i = 3 - 5;
    f3.d = 2.71;

    // Compare byte sequences
    if (std::memcmp(&f1, &f2, sizeof(FundamentalTypes)) == 0) {
        std::cout << "f1 and f2 are same" << std::endl;
    } else {
        std::cout << "f1 and f2 are different" << std::endl;
    }

    if (std::memcmp(&f1, &f3, sizeof(FundamentalTypes)) == 0) {
        std::cout << "f1 and f2 are same" << std::endl;
    } else {
        std::cout << "f1 and f2 are different" << std::endl;
    }

    return 0;
}
