#include <iostream>
#include <sstream>
#include <string>
#include <stack>

static const std::string operators = "+-*/";
static const std::string separators = " \t" + operators;

static std::string parseExpression(const std::string& user_input) {
    std::ostringstream buf {};
    std::stack<char> ops {};
    std::stack<double> values {};

    for (size_t i = 0; i < user_input.size(); ++i) {
        auto c = user_input[i];

        if (separators.find_first_of(c) != std::string::npos) {
            try {
                auto value = stod(buf.str());
                values.push(value);
            } catch (const std::invalid_argument e) {
                std::cout << "Parser failed" << std::endl;
                return "";
            } catch (const std::out_of_range e) {
                std::cout << "Value is out of range" << std::endl;
                return "";
            }

            ops.push(c);
            buf.clear();

            continue;
        }

        buf << c;

        if (i == (user_input.size() - 1)) {
            try {
                auto value = stod(buf.str());
                values.push(value);
            } catch (const std::invalid_argument e) {
                std::cout << "Parser failed" << std::endl;
                return "";
            } catch (const std::out_of_range e) {
                std::cout << "Value is out of range" << std::endl;
                return "";
            }
        }
    }

    double result = 0.0;

    while (!ops.empty()) {
        auto op = ops.top();
        ops.pop();
        auto rv = values.top();
        values.pop();
        auto lv = values.top();
        values.pop();

        switch (op) {
            case '+':
                result += lv + rv;
                break;
            case '-':
                result += lv - rv;
                break;
            case '*':
                result += lv * rv;
                break;
            case '/':
                result += lv / rv;
                break;
            default:
                return "Invalid operator";
                break;
        }
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
