#include <iostream>

#include "swap.hpp"

// GCD
int GreatestCommonDivisor(int a, int b) {
    while (a != 0) {
        b = b % a;
        Swap(&a, &b);
    }
    return b;
}

// LCM
int LeastCommonMultiple(int a, int b) {
    int gcd = GreatestCommonDivisor(a, b);
    return a * b / gcd;
}

int main() {
    int a = 12;
    int b = 18;

    std::cout << "The LCM of " << a << " and " << b << " is "
              << LeastCommonMultiple(a, b) << std::endl;

    return 0;
}
