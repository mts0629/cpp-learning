#include "node.hpp"

#include <stdexcept>

namespace Calc {

void Node::attachLeft(std::shared_ptr<Node>& node) {
    if (this->lhs_) {
        return;
    }

    this->lhs_ = node;
    this->lhs_->parent_ = shared_from_this();
}

void Node::attachRight(std::shared_ptr<Node>& node) {
    if (this->rhs_) {
        return;
    }

    this->rhs_ = node;
    this->rhs_->parent_ = shared_from_this();
}

std::shared_ptr<Node> Node::swapLeft(std::shared_ptr<Node>& node) {
    if (!this->lhs_) {
        return nullptr;
    }

    auto lhs = this->lhs_;

    this->lhs_ = node;
    this->lhs_->parent_ = shared_from_this();

    return lhs;
}

std::shared_ptr<Node> Node::swapRight(std::shared_ptr<Node>& node) {
    if (!this->rhs_) {
        return nullptr;
    }

    auto rhs = this->rhs_;

    this->rhs_ = node;
    this->rhs_->parent_ = shared_from_this();

    return rhs;
}

double Node::eval() {
    if (this->type_ == NodeType::Number) {
        return this->value_;
    }

    if ((this->lhs_ == nullptr) || (this->rhs_ == nullptr)) {
        throw std::runtime_error("Operands are lacking");
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
            throw std::runtime_error("Invalid operator");
            break;
    }

    return this->value_;
}

}  // namespace Calc
