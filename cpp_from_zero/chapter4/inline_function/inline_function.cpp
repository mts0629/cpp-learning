#include "def.hpp"

int main() {
    // Call inline function defined in defs.hpp
    // The definition is expected to be expanded at call site
    ProcInline();

    return 0;
}
