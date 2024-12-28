#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <string>
#include <vector>

namespace Calc {

enum class NodeType { INVALID, NUMBER, ADD, SUB, MUL, DIV };

class Node {
public:
    Node(const double value)
        : type_(NodeType::NUMBER),
          value_(value),
          lhs_(nullptr),
          rhs_(nullptr) {}

    Node(const NodeType op)
        : type_(op), value_(0), lhs_(nullptr), rhs_(nullptr) {}

    const std::unique_ptr<Node>& left() { return this->lhs_; }

    const std::unique_ptr<Node>& right() { return this->rhs_; }

    double eval();

    bool isNumber() { return this->type_ == NodeType::NUMBER; }

    bool isOperator() { return !isNumber(); }

    void appendLeft(std::unique_ptr<Node>& node) {
        this->lhs_.reset();
        this->lhs_ = std::move(node);
    }

    void appendRight(std::unique_ptr<Node>& node) {
        this->rhs_.reset();
        this->rhs_ = std::move(node);
    }

private:
    NodeType type_;
    double value_;
    std::unique_ptr<Node> lhs_;
    std::unique_ptr<Node> rhs_;
};

}  // namespace Calc

#endif  // NODE_HPP
