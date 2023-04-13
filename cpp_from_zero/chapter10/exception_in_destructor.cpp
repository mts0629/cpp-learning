#include <iostream>

class DestructorAndException {
public:
    // The destrucor is noexcept implicitly
    ~DestructorAndException() noexcept(false) {
        // It is executed by the time that the exception is caught
        std::cout << "~DestructorAndException() is called." << std::endl;

        // Throw an exception addtionally
        throw std::runtime_error("~DestructorAndException()");
    }
};

int main() {
    // If the exception is thrown by the time that the previous exception is caught,
    // std::terminate will be called and the program will abort
    try {
        DestructorAndException obj;
        throw std::runtime_error("main()");
        // If an exception is thrown in ~DestructorAndException(),
        // std::terminate will be called
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
