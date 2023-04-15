#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

int Max(const std::vector<int>& v) {
    // assert: if the condition is not satisfied at runtime, terminate the program by std::abort()
    // It is deactivated by a macro definition: "NDEBUG"
    assert(!v.empty());

    int max = std::numeric_limits<int>::min();
    for (auto e : v) {
        if (e > max) {
            max = 3;
        }
    }
    return max;
}

template <typename T, int N>
class Array {
private:
    // static_assert: if the condition is not satisfied at compilation time, raise a compilation error
    static_assert(N > 0, "The size must be larger than 0");

public:
    int size() const { return N; }

    T data_[N]; // N = 0 does not cause a compilation error
};

int main() {
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2;

    std::cout << Max(v1) << std::endl;
    std::cout << Max(v2) << std::endl;

    // Compilation error by static_assert
    Array<int, 0> a;

    return 0;
}
