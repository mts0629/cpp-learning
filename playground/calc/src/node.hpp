#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <string>
#include <vector>

namespace Calc {

enum class NodeType { Invalid, Number, Add, Sub, Mul, Div };

class Node : public std::enable_shared_from_this<Node> {
public:
    Node(const double value)
        : type_(NodeType::Number),
          value_(value),
          lhs_(nullptr),
          rhs_(nullptr),
          parent_(nullptr) {}

    Node(const NodeType op)
        : type_(op),
          value_(0),
          lhs_(nullptr),
          rhs_(nullptr),
          parent_(nullptr) {}

    ~Node() {}

    NodeType type() { return this->type_; }

    const std::shared_ptr<Node>& left() { return this->lhs_; }
    const std::shared_ptr<Node>& right() { return this->rhs_; }
    const std::shared_ptr<Node>& parent() { return this->parent_; }

    bool isOperator() {
        return (this->type_ == NodeType::Add) ||
               (this->type_ == NodeType::Sub) ||
               (this->type_ == NodeType::Mul) || (this->type_ == NodeType::Div);
    }

    double eval();

    void attachLeft(std::shared_ptr<Node>& node);
    void attachRight(std::shared_ptr<Node>& node);

    std::shared_ptr<Node> swapLeft(std::shared_ptr<Node>& node);
    std::shared_ptr<Node> swapRight(std::shared_ptr<Node>& node);

private:
    NodeType type_;
    double value_;

    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    std::shared_ptr<Node> parent_;
};

}  // namespace Calc

#endif  // NODE_HPP
