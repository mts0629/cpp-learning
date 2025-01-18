#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Calc {

enum class NodeType { Invalid, Number, Variable, Add, Sub, Mul, Div };

class Node : public std::enable_shared_from_this<Node> {
public:
    Node(const std::string& token)
        : type_(NodeType::Variable),
          value_(0),
          symbol_(token),
          lhs_(nullptr),
          rhs_(nullptr) {}

    Node(const double value)
        : type_(NodeType::Number),
          value_(value),
          symbol_(""),
          lhs_(nullptr),
          rhs_(nullptr) {}

    Node(const NodeType op, const std::shared_ptr<Node> left,
         const std::shared_ptr<Node> right)
        : type_(op), value_(0), symbol_(""), lhs_(left), rhs_(right) {}

    Node(const NodeType op, const std::shared_ptr<Node> right)
        : type_(op), value_(0), symbol_(""), lhs_(nullptr), rhs_(right) {}

    ~Node() {}

    NodeType type() { return this->type_; }
    const std::string& symbol() { return this->symbol_; }

    const std::shared_ptr<Node>& left() { return this->lhs_; }
    const std::shared_ptr<Node>& right() { return this->rhs_; }

    void assign(std::shared_ptr<Node>& node);

    double eval();

    static std::shared_ptr<Node> CreateNumber(const std::string& token);

    static std::shared_ptr<Node> CreateVariable(const std::string& token);

    static std::shared_ptr<Node> CreateBinaryOperator(
        const std::string& token, std::shared_ptr<Node>& left,
        std::shared_ptr<Node>& right);

    static std::shared_ptr<Node> CreateUnaryOperator(
        const std::string& token, std::shared_ptr<Node>& right);

    static void StoreVariable(const std::shared_ptr<Node>& var);
    static std::shared_ptr<Node> CallVariable(const std::string& symbol);

private:
    NodeType type_;
    double value_;
    std::string symbol_;

    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;

    static std::unordered_map<std::string, std::shared_ptr<Node>> variables_;
};

}  // namespace Calc

#endif  // NODE_HPP
