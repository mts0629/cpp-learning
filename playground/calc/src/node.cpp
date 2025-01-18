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

}  // namespace

namespace Calc {

std::unordered_map<std::string, std::shared_ptr<Node>> Node::variables_{};

void Node::assign(std::shared_ptr<Node>& node) {
    if (this->type_ != NodeType::Variable) {
        std::cerr << "[Error] only variables can be assigned\n";
        return;
    }

    this->rhs_ = node;
}

double Node::eval() {
    if (this->type_ == NodeType::Number) {
        return this->value_;
    }

    if (this->type_ == NodeType::Variable) {
        if (this->rhs_ == nullptr) {
            std::cerr << "[Error] variable \"" << this->symbol_
                      << "\" is unassigned\n";
            return std::numeric_limits<double>::infinity();
        }

        return this->rhs_->eval();
    }

    if ((this->lhs_ == nullptr) && (this->rhs_ == nullptr)) {
        std::cerr << "[Error] operand is lacking\n";
        return std::numeric_limits<double>::infinity();
    }

    if (this->lhs_ == nullptr) {
        // Unary operator
        auto rhs = this->rhs_->eval();
        switch (this->type_) {
            case NodeType::Add:
                this->value_ = rhs;
                break;
            case NodeType::Sub:
                this->value_ = -rhs;
                break;
            default:
                std::cerr << "[Error] operand is lacking\n";
                return std::numeric_limits<double>::infinity();
                break;
        }
    } else {
        // Binary operator
        if (this->rhs_ == nullptr) {
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

static bool isValidAsVariable(const std::string& token) {
    if (!isalpha(token[0])) {
        return false;
    }

    for (auto i = 1U; i < token.size(); i++) {
        if (!isalnum(token[i]) && (token[i] != '_')) {
            return false;
        }
    }

    return true;
}

std::shared_ptr<Node> Node::CreateVariable(const std::string& token) {
    if (!isValidAsVariable(token)) {
        std::cerr << "[Error] variable \"" + token +
                         "\" is invalid (format: `[a-zA-Z]+[a-zA-Z0-9]*`)\n";
        return nullptr;
    }

    return std::make_shared<Node>(token);
}

static bool isValidAsOperator(const std::string& token) {
    return operator_table.find(token) != operator_table.end();
}

std::shared_ptr<Node> Node::CreateBinaryOperator(const std::string& token,
                                                 std::shared_ptr<Node>& left,
                                                 std::shared_ptr<Node>& right) {
    if (!isValidAsOperator(token)) {
        std::cerr << "[Error] invalid token: \"" + token + "\"\n";
        return nullptr;
    }

    return std::make_shared<Node>(operator_table[token], left, right);
}

std::shared_ptr<Node> Node::CreateUnaryOperator(const std::string& token,
                                                std::shared_ptr<Node>& right) {
    if ((token != "+") && (token != "-")) {
        std::cerr << "[Error] invalid token: \"" + token + "\"\n";
        return nullptr;
    }

    return std::make_shared<Node>(operator_table[token], right);
}

void Node::StoreVariable(const std::shared_ptr<Node>& var) {
    Node::variables_[var->symbol()] = var;
}

std::shared_ptr<Node> Node::CallVariable(const std::string& symbol) {
    auto var = Node::variables_.find(symbol);
    if (var == Node::variables_.end()) {
        return nullptr;
    }

    return var->second;
}

}  // namespace Calc
