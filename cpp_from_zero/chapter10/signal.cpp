#include <csignal>
#include <exception>
#include <iostream>

// Signal handler
void signal_handler(int signal) {
    std::cout << "Received signal " << signal << std::endl;
}

int main() {
    // Signal: messages sent to / from the another program for request notification
    // especially in *nix OS

    // SIGABRT: abnormal termination condition
    throw std::exception(); // std::abort() raises SIGABRT in std::terminate()

    // SIGFPE: erroneous arithmetic operation
    int x = 2;
    int y = 0;
    int z = x / y; // Divide by zero

    // SIGSEGV: invalid memory access (segmentation fault)
    int* px = nullptr;
    std::cout << *px << std::endl;

    // SIGILL: invalid program image, such as invalid instruction
    // SIGINT: interrption by the user operation
    // SIGTERM: termination request

    // Install a signal hander
    std::signal(SIGTERM, signal_handler);

    // Send a signal
    std::raise(SIGTERM);

    return 0;
}
