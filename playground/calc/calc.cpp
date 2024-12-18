#include <iostream>
#include <sstream>
#include <string>
#include <queue>

static const std::string operators = "+-*/";
static const std::string separators = " \t" + operators;

static bool isSeparator(const char c) {
    return separators.find_first_of(c) != std::string::npos;
}

static bool isOperator(const char c) {
    return operators.find_first_of(c) != std::string::npos;
}

static bool parseValue(double& value, const std::string& token) {
    try {
        auto v = stod(token);
        value = v;
    } catch (const std::invalid_argument e) {
        std::cout << "Invalid token: \"" << token << "\"" << std::endl;
        return false;
    } catch (const std::out_of_range e) {
        std::cout << "Value \"" << token << "\" is out of range" << std::endl;
        return false;
    }

    return true;
}

static void parseExpression(const std::string& user_input) {
    std::ostringstream buf {};
    std::queue<char> ops {};
    std::queue<double> values {};

    for (auto it = user_input.begin(); it != user_input.end(); ++it) {
        auto c = *it;

        if (isSeparator(c) || (it == (user_input.end() - 1))) {
            if (!isSeparator(c)) {
                buf << c;
            } else if (isOperator(c)) {
                ops.push(c);
            }

            auto token = buf.str();
            if (token.size() == 0) {
                continue;
            }

            double value;
            if (parseValue(value, token)) {
                values.push(value);
                buf.str("");
                continue;
            }

            return;
        }

        buf << c;
    }

    if ((ops.size() != 1) || (values.size() != 2)) {
        std::cout << "Format: VALUE1 ['+'|'-'|'*'|'/'] VALUE2" << std::endl;
        return;
    }

    double result = 0.0;

    auto op = ops.front();
    ops.pop();
    auto v1 = values.front();
    values.pop();
    auto v2 = values.front();
    values.pop();

    switch (op) {
        case '+':
            result += v1 + v2;
            break;
        case '-':
            result += v1 - v2;
            break;
        case '*':
            result += v1 * v2;
            break;
        case '/':
            result += v1 / v2;
            break;
        default:
            std::cout << "Invalid operator: \'" << op << "\'" << std::endl;
            return;
            break;
    }

    std::cout << result << std::endl;
}

int main() {
    while (true) {
        std::cout << "> ";

        std::string user_input {};
        std::getline(std::cin, user_input);

        if (user_input == "q") {
            break;
        }

        parseExpression(user_input);
    }

    return 0;
}
