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

static std::shared_ptr<Node>& assignNextNode(std::shared_ptr<Node>& current,
                                             std::shared_ptr<Node>& root,
                                             std::shared_ptr<Node>& next) {
    if (!current) {
        root = next;
        return next;
    }

    if (next->isOperator()) {
        auto current_type = current->type();
        auto next_type = next->type();

        if (current_type == Calc::NodeType::Number) {
            next->attachLeft(current);
            root = next;
            return next;
        }

        // Attach the next node based on the priority of operators
        if (node_priority[next_type] > node_priority[current_type]) {
            // If the next node is higher priority
            auto prev_rhs = current->swapRight(next);
            next->attachLeft(prev_rhs);
            return next;
        } else if (node_priority[next_type] < node_priority[current_type]) {
            // If the next node is lower priority
            if (current->parent()) {
                auto parent = current->parent();
                return assignNextNode(parent, root, next);
            } else {
                next->attachLeft(current);
                root = next;
                return next;
            }
        } else {
            // Next node is same priority
            if (current->parent()) {
                auto parent = current->parent();
                return assignNextNode(parent, root, next);
            } else {
                next->attachLeft(current);
                root = next;
                return next;
            }
        }
    } else {
        if (next->type() == Calc::NodeType::Number) {
            if (current->right()) {
                throw std::runtime_error("No corresponding operators to " +
                                         std::to_string(next->eval()));
            }

            current->attachRight(next);
        } else {
            throw std::runtime_error("Node type is invalid");
        }
    }

    return current;
}

std::shared_ptr<Node> Parser::parse(const std::vector<std::string>& tokens) {
    std::shared_ptr<Node> root{nullptr};
    std::shared_ptr<Node> current = root;

    for (auto token : tokens) {
        auto next = createNode(token);
        current = assignNextNode(current, root, next);
    }

    return root;
}

}  // namespace Calc
