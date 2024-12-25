#include "exprnode.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

namespace {

static const std::string operators = "+-*/";
static const std::string separators = " \t" + operators;

}

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

static void flushCurrentToken(
    std::vector<std::string>& tokens, std::ostringstream& buf
) {
    tokens.push_back(buf.str());
    buf.str("");
}

std::vector<std::string> tokenize(const std::string& str) {
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

static double parseNumber(const std::string& token) {
    try {
        return stod(token);
    } catch (const std::invalid_argument& e) {
        std::cout << "Invalid token: \"" << token << "\"" << std::endl;
        throw e;
    } catch (const std::out_of_range& e) {
        std::cout << "Value \"" << token << "\" is out of range" << std::endl;
        throw e;
    }
}

std::unique_ptr<ExprNode> parseToExpression(const std::vector<std::string>& tokens) {
    std::unique_ptr<ExprNode> root {nullptr};

    for (auto token : tokens) {
        std::unique_ptr<ExprNode> node {nullptr};

        if (isOperator(token[0])) {
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
            node = std::make_unique<ExprNode>(optype);
        } else {
            double number = parseNumber(token);
            node = std::make_unique<ExprNode>(number);
        }

        if (root == nullptr) {
            root = std::move(node);
            continue;
        }

        if (node->isOperator()) {
            node->addLhs(root);
            root.reset();
            root = std::move(node);
        } else {
            if (root->isLhsBlank()) {
                root->addLhs(node);
            } else if (root->isRhsBlank()) {
                root->addRhs(node);
            } else {
                throw std::runtime_error(
                    "No corresponding operators to " + \
                    std::to_string(node->eval())
                );
            }
        }
    }

    return root;
}

} // namespace Calc
