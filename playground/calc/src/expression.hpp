#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <memory>
#include <string>

#include "node.hpp"

namespace Calc {

class Expression {
public:
    Expression(std::unique_ptr<Node>& root) { this->root_ = std::move(root); }

    double eval() { return root_->eval(); }

private:
    std::unique_ptr<Node> root_;
};

Expression createExpression(std::string& str);

}  // namespace Calc

#endif
