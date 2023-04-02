#include <iostream>
#include <vector>

int ReturnValue() {
    return 10;
}

struct ManyValues {
    int values[10000];
};

// Using reference for copy
void CopyManyValues(std::vector<int>& src, std::vector<int>& dst) {
    std::cout << "Copy" << std::endl;
    dst = src;
}

// Using rvalue reference for move
void CopyManyValues(std::vector<int>&& src, std::vector<int>& dst) {
    std::cout << "Move" << std::endl;
    dst = std::move(src);
}

int main() {
    // lvalue: a, rvalue: 300
    int a = 300;
    // lvalue: b, rvalue: a temporal object returned by the function ReturnValue
    int b = ReturnValue();
    // lvalue: b, c
    int c = b;

    std::vector<int> x(1000000);
    // Move
    // Pass a resource from an object to the another object for copying value w/o deep copy
    // An "ownership" is moved from x to y and x cannot be used after moving
    std::vector<int> y = std::move(x);

    // rvalue reference
    int&& r = 100;

    std::vector<int> v1(100000);
    std::vector<int> v2;
    std::vector<int> v3;

    // rvalue reference is different type with (lvalue) reference
    // Therefore different function will be called by function overload
    CopyManyValues(v1, v2);
    CopyManyValues(std::move(v1), v3);

    return 0;
}
