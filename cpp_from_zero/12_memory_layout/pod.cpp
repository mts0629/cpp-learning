#include <array>
#include <cstdint> // Symbols are in namespace std
// #include <stdint.h>  // If ABI compatibility with C is required, use C-type header
#include <type_traits>
#include <vector>

enum Direction {
    kLeft,
    kRight,
    kBoth
};

struct Empty {};

struct FundamentalTypes {
    int16_t i;
    double d;
};

struct FundamentalTypesAsChild {
    char c;
    FundamentalTypes f;
};

struct FundamentalTypesAsGrandChild {
    char c;
    FundamentalTypesAsChild f;
};

struct UserDefinedDefaultConstructor {
    UserDefinedDefaultConstructor() {}
};

struct DefaultConstructorAsExplicitDefault {
    DefaultConstructorAsExplicitDefault() = default;
};

struct VirtualFunction {
    virtual void Hoge() {}
};

struct NonPodMemberVariable {
    std::vector<int> v;
};

struct MultipleAccessSpecifierTypes {
private:
    int private_variable;

public:
    int public_variable;
};

class FundamentalTypesClass {
public:
    int16_t i;
    double d;
};

int main() {
    // POD (Plain Old Data): data structure which has ABI compatibility with C

    // Ensure POD compatibility by std::is_pod
    // Fundamental types are POD
    static_assert(std::is_pod<char>::value, "Should be PDD");
    static_assert(std::is_pod<int32_t>::value, "Should be PDD");
    static_assert(std::is_pod<double>::value, "Should be PDD");
    static_assert(std::is_pod<Direction>::value, "Should be PDD");

    // Array of POD is POD
    static_assert(std::is_pod<int[2]>::value, "Should be POD");
    static_assert(std::is_pod<std::array<int, 2>>::value, "Should be POD");

    // std::vector of POD is not POD
    static_assert(std::is_pod<std::vector<int>>::value, "Should be POD");

    // Reference is not POD
    static_assert(std::is_pod<int&>::value, "Should be POD");

    // Pointer is POD
    static_assert(std::is_pod<int*>::value, "Should be POD");
    static_assert(std::is_pod<std::vector<int>*>::value, "Should be POD");

    // struct is POD when:
    // * No inheritance
    // * No member functions (no explicit definitions for functions which defined implicitly)
    // * All data members are POD
    // * Only one access specifier (include implicit "public")
    static_assert(std::is_pod<Empty>::value, "Should be PDD");
    static_assert(std::is_pod<FundamentalTypes>::value, "Should be PDD");
    // POD struct can be nested
    static_assert(std::is_pod<FundamentalTypesAsChild>::value, "Should be PDD");
    static_assert(std::is_pod<FundamentalTypesAsGrandChild>::value, "Should be PDD");

    // struct with user-defined constructor is not POD
    // Same with special functions which are defined implicitly
    static_assert(std::is_pod<UserDefinedDefaultConstructor>::value, "Should be PDD");
    // struct with default constructor is POD
    static_assert(std::is_pod<DefaultConstructorAsExplicitDefault>::value, "Should be PDD");
    // struct with virtual function is not POD
    static_assert(std::is_pod<VirtualFunction>::value, "Should be PDD");
    // struct with non-POD member is not POD
    static_assert(std::is_pod<NonPodMemberVariable>::value, "Should be PDD");
    // struct with multiple access specifiers is not POD
    static_assert(std::is_pod<MultipleAccessSpecifierTypes>::value, "Should be PDD");

    // class will be POD by the same condition with struct
    static_assert(std::is_pod<FundamentalTypesClass>::value, "Should be PDD");

    // C++ is not fully-compatible with C
    // For example, compound literal cannot be used in C++
    // A macro "__cplusplus" can be used for change source code between C++ and C
#ifdef __cplusplus
    int* arr = std::array<int, 5>({1, 2, 3, 4, 5}).data();
#else
    // Compound literal
    int* arr = (int[]){1, 2, 3, 4, 5};
#endif
    // It will make difficult to ensure that
    // the same memory layout is used for C++ and C

    return 0;
}
