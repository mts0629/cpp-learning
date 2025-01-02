#include "parser.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

static std::vector<char> operators = {'+', '-', '*', '/'};

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

static std::shared_ptr<Node> createOperator(std::string& token) {
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

static std::shared_ptr<Node> createNode(std::string& token) {
    if (isOperator(token[0])) {
        return createOperator(token);
    }

    return createNumber(token);
}

std::shared_ptr<Node> Parser::parse(const std::vector<std::string>& tokens) {
    std::shared_ptr<Node> root{nullptr};

    for (auto token : tokens) {
        auto node = createNode(token);

        if (root == nullptr) {
            root = node;
            continue;
        }

        if (node->isOperator()) {
            auto tmp = root;
            node->attachLeft(tmp);
            root.reset();
            root = node;
        } else {
            if (root->left() == nullptr) {
                root->attachLeft(node);
            } else if (root->right() == nullptr) {
                root->attachRight(node);
            } else {
                throw std::runtime_error("No corresponding operators to " +
                                         std::to_string(node->eval()));
            }
        }
    }

    return root;
}

}  // namespace Calc
