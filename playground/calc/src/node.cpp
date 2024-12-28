#include "node.hpp"

#include <stdexcept>

namespace Calc {

double Node::eval() {
    if (this->type_ == NodeType::NUMBER) {
        return this->value_;
    }

    if ((this->lhs_ == nullptr) || (this->rhs_ == nullptr)) {
        throw std::runtime_error("Operands are lacking");
    }

    auto lhs = this->lhs_->eval();
    auto rhs = this->rhs_->eval();

    switch (this->type_) {
        case NodeType::ADD:
            this->value_ = lhs + rhs;
            break;
        case NodeType::SUB:
            this->value_ = lhs - rhs;
            break;
        case NodeType::MUL:
            this->value_ = lhs * rhs;
            break;
        case NodeType::DIV:
            this->value_ = lhs / rhs;
            break;
        default:
            throw std::runtime_error("Invalid operator");
            break;
    }

    return this->value_;
}

}  // namespace Calc
