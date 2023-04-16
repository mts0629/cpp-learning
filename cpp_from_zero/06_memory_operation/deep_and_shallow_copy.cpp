#include <iostream>

void ChangeToFifty(int v) {
    v = 50; // Deep copy
    std::cout << "v = " << v << std::endl;
}

void ChangeToFifty(int* v) {
    *v = 50; // Shallow copy
    std::cout << "*v = " << *v << std::endl;
}

int main() {
    // Deep copy: copy all values of the copied object
    int x = 100;
    std::cout << "x = " << x << std::endl;
    int y = x;
    y = 50;
    std::cout << "x = " << x << std::endl; // 100

    // Shallow copy: copy only a reference to the copied object
    int* x2 = new int(100);
    int* y2 = x2;
    *y2 = 50;
    std::cout << "*x2 = " << *x2 << std::endl; // 50

    ChangeToFifty(x);
    std::cout << "x = " << x << std::endl; // 100

    ChangeToFifty(&x);
    std::cout << "x = " << x << std::endl; // 50

    return 0;
}
