#include <iostream>
#include <cstdint>
#include <bitset>
#include <functional>

// Forward declaration
// void HelloWorld(int n);

// Function
void HelloWorld(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << "[" << i << "] " << "Hello world!" << std::endl;
    }
}

// Function overload
void Print(int x) {
    std::cout << "int: " << x << std::endl;
}

void Print(double x) {
    std::cout << "double: " << x << std::endl;
}

int Add(int x, int y) {
    return x + y;
}

int main(int argc, char* argv[]) {
    {
        // Initialize integer variable
        int x = 5;
        std::cout << "x = " << x << std::endl;

        // The value is indeterminate without assignment or initialization
        int y;
        std::cout << "y = " << y << std::endl;
        y = 5;
        std::cout << "y = " << y << std::endl;
    }

    {
        // Constant in runtime
        const int x = 5;
        // x = 10; // Compilation error

        // Constant in compilation time
        constexpr int cex = 5 * 10;
    }

    {
        // bool
        bool ok = true;

        // char
        char c = 'x';
        std::cout << "c = " << c << std::endl;

        // short
        short s = 60000;
        // long
        long l = 8000000000;
        // Unsigned integer
        unsigned int u = 4000000000;

        // Integer with size from <cstdint>
        std::int8_t i8;
        std::int16_t i16;
        std::int32_t i32;
        std::int64_t i64;
        std::uint8_t u8;
        std::uint16_t u16;
        std::uint32_t u32;
        std::uint64_t u64;

        // Floating point number
        float f = 3.141529; // Single-presicion
        double d = 3.141529653589; // Double-precision
    }

    {
        // Enumeration type
        enum Day {
            Sun = 0,
            Mon, // = 1
            Tue, // = 2
            Wed, // = 3
            Thu = 5,
            Fri, // = 6
            Sat  // = 7
        };
        Day day = Fri;
        // Can be used as integer
        int iday = Fri;
        // Day day = 5; // Compilation error

        // Compilation error
        // enum SolarSystem {
        //     Sun, // Redeclaration of "Sun"
        //     Marcury,
        //     Venus,
        //     Earth,
        //     Mars,
        //     Jupiter,
        //     Saturn,
        //     Uranus,
        //     neptune,
        // };
    }

    {
        // enum class
        enum class Day {
            Sun,
            Mon,
            Tue,
            Wed,
            Thu,
            Fri,
            Sat
        };
        Day day = Day::Fri;
        // Day day = Fri; // Compilation error
        // iday = Day::Fri; // Compilation error
        int iday = static_cast<int>(Day::Fri);

        enum class SolarSystem {
            Sun, // SolarSystem::Sun is different with Day::Sun
            Marcury,
            Venus,
            Earth,
            Mars,
            Jupiter,
            Saturn,
            Uranus,
            neptune,
        };
    }

    {
        // Integer literals
        int i_dec = 26;     // Decimal
        int i_oct = 032;    // Octal
        int i_hex = 0x1a;   // Hexadecimal
        i_hex = 0x1A; // Same with small capital
        unsigned u = 26u;   // Unsigned
        long l = 26l;       // Long
        unsigned long ul = 26ul; // Unsigned long

        float f = 3.141592f; // float
    }

    {
        int x = 5;
        // Pointer to int
        int* p = &x;
        std::cout << "p = " << p << std::endl;
        // Dereference
        std::cout << "*p = " << *p << std::endl;
        // Null pointer
        p = nullptr;

        // Pointer to const int
        const int* pc = &x;
        // *pc = 123; // Compilation error
        int y = 6;
        pc = &y; // OK

        // Const pointer to int
        int* const cp = &x;
        // cp = &y; // Compilation error
        *cp = 6; // OK

        // Const pointer to const int
        const int* const cpc = &x;
        // Compilation error
        // cpc = &y;
        // *cpc = 6;

        // Reference
        int& r = x; // Initializer is mandatory
        // Can be used in a similar way with a normal variable
        std::cout << "r = " << r << std::endl;
        r = 100;
        std::cout << "r = " << r << std::endl;
    }

    {
        int x = 5;

        // if statement
        if (x == 5) {
            std::cout << "x is five" << std::endl;
        } else if (x < 0) {
            std::cout << "x is negative" << std::endl;
        } else {
            std::cout << "x is " << x << std::endl;
        }

        // switch statement
        // The number of comparison will be lesser than if-else sequence
        switch (x) {
            case 0:
                std::cout << "x is zero" << std::endl;
                break;
            case 1:
                std::cout << "x is one" << std::endl;
                break;
            // Fall through
            case 2:
            case 3:
                std::cout << "x is two or three" << std::endl;
                break;
            default:
                std::cout << "x is " << x << std::endl;
                break;
        }

        bool done = false;

        // while
        while (!done) {
            x += (x - 3);

            std::cout << x << std::endl;

            if (x % 5 == 0) {
                done = true;
            }
        }

        x = 5;
        done = false;

        // do-while
        do {
            x += (x - 3);

            std::cout << x << std::endl;

            if (x % 5 == 0) {
                done = true;
            }
        } while (!done);

        // for
        for (int i = 0; i < 10; ++i) {
            std::cout << i << std::endl;
        }

        x = 5;

        // break
        while (true) {
            x += (x - 3);

            std::cout << x << std::endl;

            if (x % 5 == 0) {
                break;
            }
        }

        // break in nested loop
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    break;
                }

                std::cout << i << ", " << j << std::endl;
            }
        }

        // continue
        for (int i = 0; i < 10; ++i) {
            if (i == 5) {
                continue;
            }

            std::cout << i << std::endl;
        }

        // continue in nested loop
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i == j) {
                    continue;
                }

                std::cout << i << ", " << j << std::endl;
            }
        }

        // continue in do-while
        do {
            std::cout << "done" << std::endl;
            continue; // Skip and go to a loop condition

            std::cout << "never reached here" << std::endl;
        } while (false); // Finish with only one execution
    }

    {
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
    }

    {
        // Call function
        HelloWorld(10);

        // Display commandline arguments
        for (int i = 0; i < argc; ++i) {
            std::cout << "argv[" << i << "]: " << argv[i] << std::endl;
        }

        // A callee is changed by the type of an argument
        Print(2);
        Print(2.1);

        // Function pointer
        // for a function which returns integer and get 2 integer arguments
        int (*fp)(int, int) = Add;
        int result = fp(3, 5);
        std::cout << result << std::endl;

        // Type inference can be used
        auto afp = Add;
    }

    {
        // Lambda expression
        // A function which returns integer and get 2 integer arguments
        auto func = [](int a, int b) -> int { return a + b; };

        int result = func(4, 6);
        std::cout << result << std::endl;

        int init = 5;

        // Outer variables can be used by lambda introducer "[]"
        // Copy capture: copied "init" is used
        auto f = [init](int a, int b) { return init + a * b; };
        // Reference capture: a reference of "init" is used
        auto g = [&init](int a, int b) { return init + a * b; };

        init = 0;

        int result_copy = f(2, 4); // init = 5
        std::cout << result_copy << std::endl;

        int result_ref = g(2, 4); // init = 0
        std::cout << result_ref << std::endl;

        auto func1 = []() -> int { return 400; }; // Omit argument
        auto func2 = []() { return 400; }; // Omit argument and return type
        auto func3 = [](int a, int b) { return a + b; };  // Return type is inferenced (int + int = int)

        // Implicit casting for function pointer when capture is not used
        int (*fp)(int, int) = [](int x, int y) { return x + y; };

        // std::function by <functional>
        std::function<int(int, int)> stdf = Add;
        result = stdf(3, 5);
        std::cout << result << std::endl;

        stdf = [](int x, int y) { return x * y; }; // Also lambda expression can be used
        std::cout << stdf(4, 7) << std::endl;
    }

    return 0;
}
