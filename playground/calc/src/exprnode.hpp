#ifndef EXPRNODE_HPP
#define EXPRNODE_HPP

#include <memory>
#include <string>
#include <vector>

namespace Calc {

enum class ExprNodeType { INVALID, NUMBER, ADD, SUB, MUL, DIV };

class ExprNode {
public:
    ExprNode(const double value)
        : type_(ExprNodeType::NUMBER),
          value_(value),
          lhs_(nullptr),
          rhs_(nullptr) {}

    ExprNode(const ExprNodeType op)
        : type_(op), value_(0), lhs_(nullptr), rhs_(nullptr) {}

    const std::unique_ptr<ExprNode>& left() { return this->lhs_; }

    const std::unique_ptr<ExprNode>& right() { return this->rhs_; }

    double eval();

    bool isNumber() { return this->type_ == ExprNodeType::NUMBER; }

    bool isOperator() { return !isNumber(); }

    void appendLeft(std::unique_ptr<ExprNode>& node) {
        this->lhs_.reset();
        this->lhs_ = std::move(node);
    }

    void appendRight(std::unique_ptr<ExprNode>& node) {
        this->rhs_.reset();
        this->rhs_ = std::move(node);
    }

private:
    ExprNodeType type_;
    double value_;
    std::unique_ptr<ExprNode> lhs_;
    std::unique_ptr<ExprNode> rhs_;
};

std::vector<std::string> tokenize(const std::string& str);

std::unique_ptr<ExprNode> parseToExpression(
    const std::vector<std::string>& tokens);

}  // namespace Calc

#endif  // EXPRNODE_HPP
