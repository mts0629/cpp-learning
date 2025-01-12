#include <iostream>

#include "parser.hpp"
#include "tokenizer.hpp"

static std::string getInput() {
    std::cout << "> ";
    std::string input{};
    std::getline(std::cin, input);

    return input;
}

static bool isQuitCommand(std::string& input) { return input == "quit"; }

int main() {
    auto tokenizer = Calc::Tokenizer();
    auto parser = Calc::Parser();

    while (true) {
        std::string input = getInput();
        if (isQuitCommand(input)) {
            break;
        }

        auto tokens = tokenizer.tokenize(input);
        auto expr = parser.parse(tokens);
        if (expr == nullptr) {
            std::cout << expr->eval() << std::endl;
        }
    }

    return 0;
}
