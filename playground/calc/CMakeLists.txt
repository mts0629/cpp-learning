cmake_minimum_required(VERSION 3.22)

project(calc CXX)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp src/exprnode.cpp src/exprnode.hpp
)
