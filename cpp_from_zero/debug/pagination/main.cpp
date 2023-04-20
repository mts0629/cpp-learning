#include <iostream>

int Fibonacchi(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return Fibonacchi(n - 1) + Fibonacchi(n - 2);
}

int main() {
    std::cout << Fibonacchi(100) << std::endl;
}
