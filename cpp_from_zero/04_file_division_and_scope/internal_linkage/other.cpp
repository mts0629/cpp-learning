#include "other.hpp"

#include <iostream>

static int x_in_other_cpp = 246; // Internal linkage

// Unnamed namespace
namespace {
    int x = 50; // Internal linkage, better way than static in global scope

    int hoge = 0; // hoge in other.cpp
} // Unnamed namespace

void Print() {
    std::cout << x << std::endl; // x can be refer from here
}

void IncrementHoge() {
    ++hoge;
}

void PrintHoge() {
    std::cout << "other.cpp: " << hoge << std::endl;
}
