#include <iostream>

// Bit-field: allocate data members with specifiled bit size
struct Bits {
    uint8_t a : 1; // 1 bit
    uint8_t b : 3; // 3 bits
    uint8_t c : 4; // 4 bits
};

struct Bool {
    uint8_t flag : 1; // Allocate with the size of uint8_t, 7 bits are unused
};

int main() {
    Bits bits = {.a = 0b1, .b = 0b111, .c = 0b1111};

    if (bits.b = 0b111) {
        std::cout << "b = 0b111" << std::endl;
    }

    std::cout << sizeof(Bits) << std::endl;
    std::cout << sizeof(Bool) << std::endl;

    return 0;
}
