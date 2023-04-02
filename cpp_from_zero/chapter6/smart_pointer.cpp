#include <iostream>
#include <memory>

int main() {
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

    return 0;
}
