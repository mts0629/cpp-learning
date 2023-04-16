#include <iostream>

#include <cstdint>

int main() {
    // Initialize integer variable
    int x = 5;
    std::cout << "x = " << x << std::endl;

    // The value is indeterminate without assignment or initialization
    int y;
    std::cout << "y = " << y << std::endl;
    y = 5;
    std::cout << "y = " << y << std::endl;

    // Constant in runtime
    const int const_x = 5;
    // Compilation error
    // const_x = 10;

    // Constant in compilation time
    constexpr int five_times_ten = 5 * 10;
    // Compilation error
    // five_times_ten = 10;

    // Bool
    bool process_is_finished = true;

    // Character
    char c = 'x';
    std::cout << "c = " << c << std::endl;

    // short
    short s = 60000;
    // long
    long  l = 8000000000;
    // Unsigned integer
    unsigned int u = 4000000000;

    // Integer with size and signature
    // <cstdint>
    std::int8_t  signed_8bit;
    std::int16_t signed_16bit;
    std::int32_t signed_32bit;
    std::int64_t signed_64bit;
    std::uint8_t  unsigned_8bit;
    std::uint16_t unsigned_16bit;
    std::uint32_t unsigned_32bit;
    std::uint64_t unsigned_64bit;

    // Floating point number
    // Single-presicion
    float  flt_pi = 3.141529;
    // Double-precision
    double dbl_pi = 3.141529653589;

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
    int day_int = Fri;
    // Compilation error
    // Day day = 5;

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

    // enum class
    enum class DayOfWeek {
        Sun,
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat
    };

    DayOfWeek day_of_week = DayOfWeek::Fri;

    // Compilation error
    // DayOfWeek day = Fri;
    // Compilation error
    // day_int = DayOfWeek::Fri;

    day_int = static_cast<int>(DayOfWeek::Fri);

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

    // Integer literals
    x = 26;     // Decimal
    x = 032;    // Octal
    x = 0x1a;   // Hexadecimal
    x = 0x1A;   // Hexadecimal, same with small capital

    l = 26l;   // Long
    u = 26u;   // Unsigned

    unsigned long ul = 26ul;  // Unsigned long

    // Float literal
    flt_pi = 3.141592f;

    return 0;
}
