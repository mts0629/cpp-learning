#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    // Input file stream
    std::ifstream ifile("./file.txt");

    // Read text file per line
    std::string line;
    while (std::getline(ifile, line)) {
        std::cout << line << std::endl;
    }

    std::vector<std::string> fruits = {
        "apple", "strawberry", "pear", "grape"
    };

    // Output file stream
    std::ofstream ofile("./bin/fruits.txt");
    for (const auto fruit: fruits) {
        ofile << fruit << std::endl;
    }

    // Append to an existing file
    std::ofstream ofs("./bin/fruits.txt", std::ios::app);
    std::string quotation("--- William Shakespeare's Epitaph");
    ofs << std::endl << quotation;

    return 0;
}
