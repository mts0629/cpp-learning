#include <iostream>
#include <fstream>
#include <vector>

enum class Day {
    Sun,
    Mon,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat
};

class Square {
public:
    explicit Square(int size) : size_(size) {}

private:
    int size_;
};

int main() {
    double dx = 3.14;
    // static_cast: cast data type explicitly
    int x = static_cast<int>(dx);
    std::cout << dx << std::endl;
    std::cout << x << std::endl;

    Day day1 = static_cast<Day>(1);
    int day2 = static_cast<int>(Day::Tue);

    // Conversion constuctor can be used if "explict" is specified
    Square square = static_cast<Square>(10);

    // dynamic_cast: cast between the pointer to the base class and
    // that of the derived class
    // Used for down casting

    // const_cast: cast to add / remove const
    const std::string str("foo");
    std::string& s = const_cast<std::string&>(str);

    std::vector<int> nums = {1, 2, 3, 4};

    std::ofstream ofs("./bin/nums.bin", std::ios::binary | std::ios::out);
    if (!ofs) {
        return 1;
    }

    // Byte size
    const auto size = sizeof(int) * nums.size();

    // reinterpret_cast: convert data type information
    // std::ofstream::write() need a data type const char* as a first argument
    ofs.write(reinterpret_cast<const char *>(nums.data()), size);

    // C-type casting can be used but an intension is not clear
    // int xx = (int)dx;

    // It will be compilation error and avoid unintentional casting
    // int *px = static_cast<int*>(x);

    return 0;
}
