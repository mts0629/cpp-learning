#include <iostream>
#include <vector>
#include <memory>

void Function() {
    // Local variables are allocated on a stack
    // Stack size is limited
    // and only variables with a known lifetime can use the stack
    int x = 100;
    int y = 200;
}

void ChangeToFifty(int v) {
    v = 50; // Deep copy
}

void ChangeToFifty(int* v) {
    *v = 50; // Shallow copy
}

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
    {
        // Stack is used in a function
        Function();
    }

    {
        // Heap is used for dynamic allocation
        // Memory allocation on a heap: new operator
        int *p1 = new int(100);
        int *p2 = new int[5]; // Array

        // Deallocation: delete operator
        delete p1;
        delete[] p2; // Deallocate an array
    }

    {
        // Deep copy
        int x = 100;
        int y = x;
        y = 50;
        std::cout << x << std::endl; // 100

        // Shallow copy: only a reference to an object are copied
        int* x2 = new int(100);
        int* y2 = x2;
        *y2 = 50;
        std::cout << *x2 << std::endl; // 50;

        ChangeToFifty(x);
        std::cout << x << std::endl; // 100

        ChangeToFifty(&x);
        std::cout << x << std::endl; // 50
    }

    {
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
    }

    {
        // Smart pointer
        // Provide automatic deallocation of dynamic-allocated resources
        {
            // Shared pointer: share an ownership of the resource
            std::shared_ptr<int> x = std::make_shared<int>(100);

            {
                // An ownership of x is shared with y
                std::shared_ptr<int> y = x;

                std::cout << *y << std::endl;
            } // y is released

            std::cout << *x << std::endl;
        } // x is released

        {
            // Unique pointer: owner is only one
            std::unique_ptr<int> x(new int(100));
            // Compilation error
            // std::unique_ptr<int> y = x;
            // Move is valid
            std::unique_ptr<int> y(std::move(x));

            std::cout << *y << std::endl;
        } // x is released

        {
            std::shared_ptr<int> sp = std::make_shared<int>(246);
            // Weak pointer
            // Watch a resource without having the ownership
            std::weak_ptr<int> wp = sp;

            // If the resource is valid, sp2 is created and sharing the resource with sp1
            std::shared_ptr<int> sp2 = wp.lock();
            if (sp2) {
                std::cout << *sp2 << std::endl;
            } else {
                std::cout << "The resource is already released" << std::endl;
            }
        }
    }

    return 0;
}
