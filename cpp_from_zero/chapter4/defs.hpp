#ifndef DEFS_HPP
#define DEFS_HPP

#include <iostream>

// Inline function
// A definition is shared with other translation unit
inline void ProcInline() {
    std::cout << "ProcInline" << std::endl;
}

#endif // DEFS_HPP
