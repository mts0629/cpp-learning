#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    {
        // Standard output
        std::cout << "Standard output" << std::endl;

        // Standard error output
        std::cerr << "Standard error output" << std::endl;

        std::cout << "Input your favorite food: ";
        std::string food;
        // Standard input
        std::cin >> food;
        std::cout << "Your favorite food is: " << food << std::endl;

        int x = 0;
        std::cout << "Input an integer: ";
        // Check a result of input
        if (std::cin >> x) {
            std::cout << "Input is: " << x << std::endl;
        } else {
            std::cout << "Your input is invalid" << std::endl;
        }
    }

    {
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
    }

    return 0;
}
