#include <iostream>

#include "expression.hpp"

int main() {
    while (true) {
        std::cout << "> ";
        std::string user_input{};
        std::getline(std::cin, user_input);

        if (user_input == "q") {
            break;
        }

        try {
            auto expr = Calc::createExpression(user_input);
            std::cout << expr.eval() << std::endl;
        } catch (const std::exception& e) {
            (void)e;
        }
    }

    return 0;
}
