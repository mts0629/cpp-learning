#include <iostream>
#include <cstdint>

int main() {
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

    return 0;
}
