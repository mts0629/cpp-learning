#include <iostream>
#include <bitset>

int main() {
    // Operator
    int add = 1 + 2; // Addition
    int sub = 4 - 2; // Subtraction
    int mul = 3 * 5; // Multiplication
    int div = 4 / 2; // Division
    int mod = 7 % 6; // Modulo
    // Zero division causes runtime error
    // int div = 100 / 0;
    // int mod = 100 % 0;

    int ix = 100;
    int iy = 50;
    double dx = 100.0;
    double dy = 50.0;
    // Implicit type casting
    auto a = ix / iy; // int = int / int
    auto b = ix / dy; // double = double(int) / double
    auto c = dx / iy; // double = double / double(int)
    auto d = dx / dy; // double = double / double

    int x = 0;
    ++x; // Pre-increment
    x++; // Post-increment
    --x; // Pre-decrement
    x--; // Post-decrement

    a = 5;
    x = 0;

    // Pre-increment/decrement adds the value before evaluation
    b = ++a;
    std::cout << "a = " << a << std::endl; // 6
    std::cout << "b = " << b << std::endl; // 6

    a = 5;
    b = 0;

    // Post-increment/decrement add the value after evaluation
    b = a++;
    std::cout << "a = " << a << std::endl; // 5
    std::cout << "b = " << b << std::endl; // 6

    // Bit operations
    x = 0xffU;
    int y = 0x0U;
    y = ~x; // Not
    y = x << 2; // Left shift
    y = x >> 2; // Right shift
    y = x & 0x01U; // And
    y = x | 0x01U; // Or
    y = x ^ 0x01U; // Xor

    // std::bitset by <bitset>
    auto bits_a = std::bitset<8>("00001111");
    std::cout << ~bits_a << std::endl;
    std::cout << (bits_a << 2) << std::endl;
    std::cout << (bits_a >> 2) << std::endl;

    auto bits_b = std::bitset<8>("00111100");
    std::cout << (bits_a & bits_b) << std::endl;
    std::cout << (bits_a | bits_b) << std::endl;
    std::cout << (bits_a ^ bits_b) << std::endl;

    // unsigned interger is good for bit operation,
    // because some of the bit operations for signed integer are
    // undefined / implementation-dependent behavior
    unsigned int ua = 0x0000000fU;
    // Set prefix and display a value with hexadecimal format
    std::cout << std::showbase << std::hex;
    std::cout << ~ua << std::endl;
    std::cout << (ua << 2) << std::endl;
    std::cout << (ua >> 2) << std::endl;

    unsigned int ub = 0x0000003cU;
    std::cout << (ua & ub) << std::endl;
    std::cout << (ua | ub) << std::endl;
    std::cout << (ua ^ ub) << std::endl;

    // Reset format
    std::cout << std::noshowbase << std::dec;

    // Composite assignment operators
    y += x;     // y = y + x
    y -= x;     // y = y - x
    y *= x;     // y = y * x
    y /= x;     // y = y / x
    y %= x;     // y = y % x
    y &= x;     // y = y & x
    y |= x;     // y = y | x
    y ^= x;     // y = y ^ x
    y <<= x;    // y = y << x
    y >>= x;    // y = y >> x

    // (Composite) assignment operator is evaluated after arithmetic operations
    x = 2;
    x *= 4 + 3;
    std::cout << x << std::endl; // 14

    y = 2;
    y = y * 4 + 3;
    std::cout << y << std::endl; // 11

    return 0;
}
