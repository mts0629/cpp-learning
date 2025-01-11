#include "parser.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

namespace Calc {

static std::shared_ptr<Node> createNumber(const std::string& token) {
    double number = 0;

    try {
        number = stod(token);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid token: \"" << token << "\"" << std::endl;
        throw e;
    } catch (const std::out_of_range& e) {
        std::cout << "Value \"" << token << "\" is out of range" << std::endl;
        throw e;
    }

    return std::make_shared<Node>(number);
}

static std::shared_ptr<Node> createOperator(const std::string& token) {
    NodeType optype = NodeType::Invalid;

    switch (token[0]) {
        case '+':
            optype = NodeType::Add;
            break;
        case '-':
            optype = NodeType::Sub;
            break;
        case '*':
            optype = NodeType::Mul;
            break;
        case '/':
            optype = NodeType::Div;
            break;
        default:
            throw std::runtime_error("Invalid operator: " + token);
            break;
    }

    return std::make_shared<Node>(optype);
}

static std::shared_ptr<Node> expr(const std::vector<std::string>& tokens,
                                  std::vector<std::string>::const_iterator& it);

static std::shared_ptr<Node> factor(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    if (*it == "(") {
        ++it;
        auto inner_expr = expr(tokens, it);

        while (*it != ")") {
            ++it;
        }
        ++it;

        return inner_expr;
    }

    auto factor = createNumber(*it);
    ++it;
    return factor;
}

static std::shared_ptr<Node> term(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    auto left = factor(tokens, it);

    while (it != tokens.end()) {
        if ((*it == "*") || (*it == "/")) {
            auto op = createOperator(*it);
            ++it;
            auto right = term(tokens, it);

            op->attachLeft(left);
            op->attachRight(right);

            return op;
        } else {
            break;
        }
    }

    return left;
}

static std::shared_ptr<Node> expr(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    auto left = term(tokens, it);

    while (it != tokens.end()) {
        if ((*it == "+") || (*it == "-")) {
            auto op = createOperator(*it);
            ++it;
            auto right = expr(tokens, it);

            op->attachLeft(left);
            op->attachRight(right);

            return op;
        } else {
            break;
        }
    }

    return left;
}

std::shared_ptr<Node> Parser::parse(const std::vector<std::string>& tokens) {
    std::vector<std::string>::const_iterator it{tokens.begin()};
    return expr(tokens, it);
}

}  // namespace Calc
