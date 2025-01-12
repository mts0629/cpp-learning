#include "node.hpp"

#include <iostream>
#include <limits>
#include <unordered_map>

namespace {

std::unordered_map<std::string, Calc::NodeType> operator_table = {
    {"+", Calc::NodeType::Add},
    {"-", Calc::NodeType::Sub},
    {"*", Calc::NodeType::Mul},
    {"/", Calc::NodeType::Div}};
}

namespace Calc {

double Node::eval() {
    if (this->type_ == NodeType::Number) {
        return this->value_;
    }

    if ((this->lhs_ == nullptr) || (this->rhs_ == nullptr)) {
        std::cerr << "[Error] operand is lacking\n";
        return std::numeric_limits<double>::infinity();
    }

    auto lhs = this->lhs_->eval();
    auto rhs = this->rhs_->eval();

    switch (this->type_) {
        case NodeType::Add:
            this->value_ = lhs + rhs;
            break;
        case NodeType::Sub:
            this->value_ = lhs - rhs;
            break;
        case NodeType::Mul:
            this->value_ = lhs * rhs;
            break;
        case NodeType::Div:
            this->value_ = lhs / rhs;
            break;
        default:
            std::cerr << "[Error] invalid operator\n";
            return std::numeric_limits<double>::infinity();
            break;
    }

    return this->value_;
}

std::shared_ptr<Node> Node::CreateNumber(const std::string& token) {
    double number = 0;

    try {
        number = stod(token);
    } catch (const std::invalid_argument& e) {
        std::cerr << "[Error] invalid token: \"" << token << "\"\n";
        return nullptr;
    } catch (const std::out_of_range& e) {
        std::cerr << "[Error] value " << token
                  << " is out of range of `double`\n";
        return nullptr;
    }

    return std::make_shared<Node>(number);
}

static bool operator_is_invalid(const std::string& token) {
    return operator_table.find(token) == operator_table.end();
}

std::shared_ptr<Node> Node::CreateBinaryOperator(const std::string& token,
                                                 std::shared_ptr<Node>& left,
                                                 std::shared_ptr<Node>& right) {
    if (operator_is_invalid(token)) {
        std::cerr << "[Error] invalid token: \"" + token + "\"\n";
        return nullptr;
    }

    return std::make_shared<Node>(operator_table[token], left, right);
}

}  // namespace Calc
