#include <iostream>

void f() {
    int v1 {100};        // Automatic storage duration
                         // Finish its lifetime when quitting this scope
    static int v2 {100}; // Static storage duration
                         // Finish its lifetime when this program end

    std::cout << "v1=" << v1 << "\n";
    std::cout << "v2=" << v2 << "\n";

    v2++; // Incremented by every function call
}

int v {100}; // Definition
             // Static storage duration

int main() {
    extern int v; // Declaration
                  // Object doesn't be constructed

    std::cout << v << "\n";
    v = 200;
    std::cout << v << "\n";

    for (int i = 0; i < 3; ++i) {
        f();
    }

    return 0;
}
