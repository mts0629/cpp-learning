#include "parser.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

namespace {

static std::vector<char> operators = {'+', '-', '*', '/'};

static std::unordered_map<Calc::NodeType, int> node_priority = {
    {Calc::NodeType::Add, 0},
    {Calc::NodeType::Sub, 0},
    {Calc::NodeType::Mul, 1},
    {Calc::NodeType::Div, 1},
};

}  // namespace

namespace Calc {

static bool isOperator(const char c) {
    for (auto s : operators) {
        if (c == s) {
            return true;
        }
    }

    return false;
}

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

static std::shared_ptr<Node> createNode(const std::string& token) {
    if (isOperator(token[0])) {
        return createOperator(token);
    }

    return createNumber(token);
}

std::shared_ptr<Node> Parser::parse(const std::vector<std::string>& tokens) {
    if (tokens.size() == 1) {
        return createNode(tokens[0]);
    }

    auto op_it = tokens.cbegin();
    auto least_priority = INT32_MAX;
    std::shared_ptr<Node> op {nullptr};
    for (auto it = tokens.cbegin(); it != tokens.cend(); ++it) {
        if (isOperator((*it)[0])) {
            op = createNode(*it);
            auto priority = node_priority[op->type()];
            if (priority < least_priority) {
                op_it = it;
                least_priority = priority;
            }
        }
    }

    op = createNode(*op_it);
    std::vector<std::string> left{tokens.cbegin(), op_it};
    std::vector<std::string> right{++op_it, tokens.cend()};

    auto lhs = parse(left);
    auto rhs = parse(right);
    op->attachLeft(lhs);
    op->attachRight(rhs);

    return op;
}

}  // namespace Calc
