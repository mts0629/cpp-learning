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
          rhs_(nullptr) {}

    Node(const NodeType op, const std::shared_ptr<Node> left,
         const std::shared_ptr<Node> right)
        : type_(op), value_(0), lhs_(left), rhs_(right) {}

    Node(const NodeType op, const std::shared_ptr<Node> right)
        : type_(op), value_(0), lhs_(nullptr), rhs_(right) {}

    ~Node() {}

    NodeType type() { return this->type_; }

    const std::shared_ptr<Node>& left() { return this->lhs_; }
    const std::shared_ptr<Node>& right() { return this->rhs_; }

    double eval();

    static std::shared_ptr<Node> CreateNumber(const std::string& token);

    static std::shared_ptr<Node> CreateBinaryOperator(
        const std::string& token, std::shared_ptr<Node>& left,
        std::shared_ptr<Node>& right);

    static std::shared_ptr<Node> CreateUnaryOperator(
        const std::string& token, std::shared_ptr<Node>& right);

private:
    NodeType type_;
    double value_;

    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
};

}  // namespace Calc

#endif  // NODE_HPP
