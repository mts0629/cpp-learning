#include <iostream>
#include <random>

int main() {
    std::random_device rand_dev {};
    std::mt19937 rand_engine(rand_dev());

    // Uniform distribution for integer [1, 6]
    std::uniform_int_distribution<int> dist(1, 6);
    for (auto i = 0; i < 10; ++i) {
        std::cout << dist(rand_engine) << std::endl;
    }

    // Uniform distribution for floating point numbers [0, 2.0]
    std::uniform_real_distribution<double> rdist(0, 2.0);
    for (auto i = 0; i < 10; ++i) {
        std::cout << rdist(rand_engine) << std::endl;
    }

    return 0;
}
