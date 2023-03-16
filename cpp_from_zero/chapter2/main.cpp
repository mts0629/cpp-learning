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
        // Compilation error
        // x = 10;

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
        // Compilation error
        // Day day = 5;

        // Compilation error: redeclaration of "Sun"
        // enum SolarSystem {
        //     Sun,
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
        // Compilation error
        // Day day = Fri;
        // Compilation error
        // iday = Day::Fri;
        // Cast is valid
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


    return 0;
}
