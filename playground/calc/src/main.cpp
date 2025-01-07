#include <iostream>

#include "parser.hpp"
#include "tokenizer.hpp"

std::string get_input() {
    std::string input{};
    std::getline(std::cin, input);

    return input;
}

int main() {
    auto tokenizer = Calc::Tokenizer();
    auto parser = Calc::Parser();

    while (true) {
        std::cout << "> ";
        std::string input = get_input();

        if (input == "q") {
            break;
        }

        try {
            auto tokens = tokenizer.tokenize(input);
            auto expr = parser.parse(tokens);
            std::cout << expr->eval() << std::endl;
        } catch (const std::exception& e) {
            (void)e;
        }
    }

    return 0;
}
