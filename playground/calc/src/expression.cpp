#include "expression.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

#include "tokenizer.hpp"

namespace {

static std::vector<char> operators = {'+', '-', '*', '/'};
static std::vector<char> separators = {'+', '-', '*', '/', ' ', '\t'};

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

static std::unique_ptr<Node> createNumberNode(const std::string& token) {
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

    return std::make_unique<Node>(number);
}

static std::unique_ptr<Node> createOperatorNode(std::string& token) {
    NodeType optype = NodeType::INVALID;

    switch (token[0]) {
        case '+':
            optype = NodeType::ADD;
            break;
        case '-':
            optype = NodeType::SUB;
            break;
        case '*':
            optype = NodeType::MUL;
            break;
        case '/':
            optype = NodeType::DIV;
            break;
        default:
            throw std::runtime_error("Invalid operator: " + token);
            break;
    }

    return std::make_unique<Node>(optype);
}

static std::unique_ptr<Node> createNode(std::string& token) {
    if (isOperator(token[0])) {
        return createOperatorNode(token);
    }

    return createNumberNode(token);
}

static Expression parseToExpression(const std::vector<std::string>& tokens) {
    std::unique_ptr<Node> root{nullptr};

    for (auto token : tokens) {
        auto node = createNode(token);

        if (root == nullptr) {
            root = std::move(node);
            continue;
        }

        if (node->isOperator()) {
            auto tmp = std::move(root);
            node->appendLeft(tmp);
            root.reset();
            root = std::move(node);
        } else {
            if (root->left() == nullptr) {
                root->appendLeft(node);
            } else if (root->right() == nullptr) {
                root->appendRight(node);
            } else {
                throw std::runtime_error("No corresponding operators to " +
                                         std::to_string(node->eval()));
            }
        }
    }

    return Expression(root);
}

Expression createExpression(std::string& str) {
    auto tokenizer = Calc::Tokenizer(separators);
    auto tokens = tokenizer.tokenize(str);
    return parseToExpression(tokens);
}

}  // namespace Calc
