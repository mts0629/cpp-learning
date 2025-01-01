#include <iostream>

#include "parser.hpp"
#include "tokenizer.hpp"

int main() {
    auto tokenizer = Calc::Tokenizer();
    auto parser = Calc::Parser();

    while (true) {
        std::cout << "> ";
        std::string user_input{};
        std::getline(std::cin, user_input);

        if (user_input == "q") {
            break;
        }

        try {
            auto tokens = tokenizer.tokenize(user_input);
            auto expr = parser.parse(tokens);
            std::cout << expr->eval() << std::endl;
        } catch (const std::exception& e) {
            (void)e;
        }
    }

    return 0;
}
