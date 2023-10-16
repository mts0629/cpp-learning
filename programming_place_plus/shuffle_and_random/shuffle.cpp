#include <algorithm> // std:shuffle
#include <iostream>
#include <random> // std::random_device, std::mt19937
#include <vector>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };

    // Random number generator (RNG), nondeterministic
    std::random_device rand_dev {};
    // Mersenne Twister PRNG (pseudorandom number generator)
    std::mt19937 rand_engine(rand_dev());

    // Shuffle the collection
    std::shuffle(std::begin(vec), std::end(vec), rand_engine);

    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    // Random number by mt19937
    auto min = std::mt19937::min();
    auto max = std::mt19937::max();
    std::cout << "mt19937: [" << min << ", " << max << "]" << std::endl;
    for (auto i = 0; i < 10; i++) {
        std::cout << rand_engine() << std::endl;
    }

    return 0;
}
