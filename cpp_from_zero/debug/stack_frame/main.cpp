#include <iostream>

int GreatestCommonDivisor(int a, int b) {
    if (a == 0) {
        return b;
    }

    return GreatestCommonDivisor(b % a, a);
}

int main() {
    int a = 12;
    int b = 18;

    std::cout << "GCD of " << a << " and " << b << " is "
              << GreatestCommonDivisor(a, b) << std::endl;

    return 0;
}
