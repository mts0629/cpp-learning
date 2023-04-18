#include "swap.hpp"

int Swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
