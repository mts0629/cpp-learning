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

static bool isStreamEmpty(std::ostringstream& buf) {
    return buf.tellp() == std::streampos(0);
}

static void flushCurrentToken(
    std::vector<std::string>& tokens, std::ostringstream& buf
) {
    tokens.push_back(buf.str());
    buf.str("");
}

static std::vector<std::string> tokenize(const std::string& str) {
    std::ostringstream buf {};
    std::vector<std::string> tokens {};

    for (auto it = str.begin(); it != str.end(); ++it) {
        auto c = *it;

        if (isSeparator(c)) {
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }
            if (!isspace(c)) {
                buf << c;
            }
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }

            continue;
        }

        buf << c;

        if (it == (str.end() - 1)) {
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }
        }
    }

    return tokens;
}

static bool parseNumber(double& value, const std::string& token) {
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

static void parseExpression(const std::vector<std::string>& tokens) {
    std::queue<char> ops {};
    std::queue<double> values {};

    for (auto token : tokens) {
        if (isOperator(token[0])) {
            ops.push(token[0]);
            continue;
        }

        double number;
        if (parseNumber(number, token)) {
            values.push(number);
            continue;
        }
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

        auto tokens = tokenize(user_input);
        parseExpression(tokens);
    }

    return 0;
}
