#include <iostream>
#include <vector>

void Function() {
    // Local variables are allocated on a stack
    // Stack size is limited and only variables with a known lifetime can use the stack
    int x = 100;
    int y = 200;

    std::cout << "x = " << x << ", y = " << y << std::endl;

    // x, y is deallocated
}

int main() {
    // Stack is used in a function
    Function();

    // std::vector uses a heap
    std::vector<int> x;

    // The size of x changes by user input
    std::size_t size_of_x;
    std::cout << "Input the number: ";
    std::cin >> size_of_x;
    for (auto i = 0; i < size_of_x; ++i) {
        x.push_back(1);
    }
    for (auto item: x) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
