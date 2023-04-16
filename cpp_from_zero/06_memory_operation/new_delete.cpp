
int main() {
    // Heap is used for dynamic allocation
    // Memory allocation to a heap: new operator
    int *p1 = new int(100);
    int *p2 = new int[5]; // Array

    // Deallocation: delete operator
    delete p1;
    delete[] p2; // Deallocate an array

    return 0;
}
