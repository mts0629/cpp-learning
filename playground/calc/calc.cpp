#include <iostream>
#include <sstream>
#include <string>

static std::string parseExpression(const std::string& user_input) {
    std::istringstream iss {user_input};

    double operand1, operand2;
    std::string op;
    iss >> operand1 >> op >> operand2;

    if (op.size() > 1) {
        return "Parser failed\n"
               "Format: OP1 ['+'|'-'|'*'|'/'] OP2";
    }

    double result = 0.0;
    switch (op[0]) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            result = operand1 / operand2;
            break;
        default:
            return "Invalid operator";
            break;
    }

    return std::to_string(result);
}

int main() {
    while (true) {
        std::cout << "> ";

        std::string user_input {};
        std::getline(std::cin, user_input);

        if (user_input == "q") {
            break;
        }

        std::cout << parseExpression(user_input) << std::endl;
    }

    return 0;
}
