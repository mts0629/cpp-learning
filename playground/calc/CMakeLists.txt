cmake_minimum_required(VERSION 3.22)

project(calc CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQURED ON)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    # v1.15.2
    URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)

# Prevent overriding compiler settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_compile_options(-Wall -Wextra -Wpedantic)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_executable(
    ${PROJECT_NAME} ${SOURCES}
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Enable ctest
enable_testing()

add_executable(
    test_tokenizer test/test_tokenizer.cpp src/tokenizer.cpp
)
target_include_directories(
    test_tokenizer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)
target_link_libraries(test_tokenizer GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_tokenizer)
