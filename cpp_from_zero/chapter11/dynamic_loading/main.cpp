#include <iostream>

#include "dlfcn.h"

#include "libfoo.hpp"

int main() {
    // Dynamic loading: load shared (dynamic) library while running a program
    // The procedure depends on the environment

    // Open a shared library
    // Get a handle of the library
    void* handle = dlopen("./libfoo.so", RTLD_NOW);
    if (handle == NULL) {
        const char* const error_message = dlerror();
        std::cerr << error_message << std::endl;
        return 1;
    }

    // Get pointers of functions and variables in the library
    // Specify the handle and symbol name in the library
    // Add()
    // Symbol names are "mangled" to identify symbols with the same name in different classes, namespaces, templates, etc.
    void* const symbol_add = dlsym(handle, "_Z3Addii");
    {
        const char* const error_message = dlerror();
        if (error_message != NULL) {
            std::cerr << error_message << std::endl;
            dlclose(handle);
            return 1;
        }
    }

    // Sub()
    // Symbol name is demangled by extern "C"
    void* const symbol_sub = dlsym(handle, "Sub");
    {
        const char* const error_message = dlerror();
        if (error_message != NULL) {
            std::cerr << error_message << std::endl;
            dlclose(handle);
            return 1;
        }
    }

    // Need to cast loaded pointers (void*) to function pointer
    auto Add = reinterpret_cast<int(*)(int, int)>(symbol_add);
    auto Sub = reinterpret_cast<int(*)(int, int)>(symbol_sub);

    // Use the functions
    std::cout << Add(1, 2) << std::endl;;
    std::cout << Sub(3, 4) << std::endl;;

    // Close the library
    dlclose(handle);

    return 0;
}
