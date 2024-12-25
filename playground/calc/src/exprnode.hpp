#ifndef EXPRNODE_HPP
#define EXPRNODE_HPP

#include <memory>
#include <string>
#include <vector>

namespace Calc {

enum class ExprNodeType {
    INVALID,
    NUMBER,
    ADD,
    SUB,
    MUL,
    DIV
};

class ExprNode {
public:
    ExprNode(const double value) :
        type_(ExprNodeType::NUMBER), value_(value), lhs_(nullptr), rhs_(nullptr) {}

    ExprNode(const ExprNodeType op) :
        type_(op), value_(0), lhs_(nullptr), rhs_(nullptr) {}

    double eval();

    bool isNumber() {
        return this->type_ == ExprNodeType::NUMBER;
    }

    bool isOperator() {
        return !isNumber();
    }

    bool isLhsBlank() {
        return this->lhs_ == nullptr;
    }

    bool isRhsBlank() {
        return this->rhs_ == nullptr;
    }

    void addLhs(std::unique_ptr<ExprNode>& node) {
        this->lhs_.reset();
        this->lhs_ = std::move(node);
    }

    void addRhs(std::unique_ptr<ExprNode>& node) {
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

std::unique_ptr<ExprNode> parseToExpression(const std::vector<std::string>& tokens);

} // namespace Calc

#endif // EXPRNODE_HPP
