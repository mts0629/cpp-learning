#include "exprnode.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

static const std::string operators = "+-*/";
static const std::string separators = " \t" + operators;

}  // namespace

namespace Calc {

double ExprNode::eval() {
    if (this->type_ == ExprNodeType::NUMBER) {
        return this->value_;
    }

    if ((this->lhs_ == nullptr) || (this->rhs_ == nullptr)) {
        throw std::runtime_error("Operands are lacking");
    }

    auto lhs = this->lhs_->eval();
    auto rhs = this->rhs_->eval();

    switch (this->type_) {
        case ExprNodeType::ADD:
            this->value_ = lhs + rhs;
            break;
        case ExprNodeType::SUB:
            this->value_ = lhs - rhs;
            break;
        case ExprNodeType::MUL:
            this->value_ = lhs * rhs;
            break;
        case ExprNodeType::DIV:
            this->value_ = lhs / rhs;
            break;
        default:
            throw std::runtime_error("Invalid operator");
            break;
    }

    return this->value_;
}

static bool isSeparator(const char c) {
    return separators.find_first_of(c) != std::string::npos;
}

static bool isOperator(const char c) {
    return operators.find_first_of(c) != std::string::npos;
}

static bool isStreamEmpty(std::ostringstream& buf) {
    return buf.tellp() == std::streampos(0);
}

static void flushCurrentToken(std::vector<std::string>& tokens,
                              std::ostringstream& buf) {
    tokens.push_back(buf.str());
    buf.str("");
}

std::vector<std::string> tokenize(const std::string& str) {
    std::ostringstream buf{};
    std::vector<std::string> tokens{};

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

static std::unique_ptr<ExprNode> createNumberNode(const std::string& token) {
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

    return std::make_unique<ExprNode>(number);
}

static std::unique_ptr<ExprNode> createOperatorNode(std::string& token) {
    ExprNodeType optype = ExprNodeType::INVALID;

    switch (token[0]) {
        case '+':
            optype = ExprNodeType::ADD;
            break;
        case '-':
            optype = ExprNodeType::SUB;
            break;
        case '*':
            optype = ExprNodeType::MUL;
            break;
        case '/':
            optype = ExprNodeType::DIV;
            break;
        default:
            throw std::runtime_error("Invalid operator: " + token);
            break;
    }

    return std::make_unique<ExprNode>(optype);
}

static std::unique_ptr<ExprNode> createNode(std::string& token) {
    if (isOperator(token[0])) {
        return createOperatorNode(token);
    }

    return createNumberNode(token);
}

std::unique_ptr<ExprNode> parseToExpression(
    const std::vector<std::string>& tokens) {
    std::unique_ptr<ExprNode> root{nullptr};

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

    return root;
}

}  // namespace Calc
