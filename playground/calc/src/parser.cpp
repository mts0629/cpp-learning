#include "parser.hpp"

#include <sstream>
#include <unordered_map>

namespace Calc {

static std::shared_ptr<Node> expr(const std::vector<std::string>& tokens,
                                  std::vector<std::string>::const_iterator& it);

static std::shared_ptr<Node> factor(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    if (*it == "(") {
        ++it;
        auto inner_expr = expr(tokens, it);

        while (*it != ")") {
            ++it;
        }
        ++it;

        return inner_expr;
    }

    auto factor = Calc::Node::CreateNumber(*it);
    ++it;
    return factor;
}

static std::shared_ptr<Node> term(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    auto left = factor(tokens, it);
    if (left == nullptr) {
        return nullptr;
    }

    while (it != tokens.end()) {
        if ((*it == "*") || (*it == "/")) {
            auto op_str{*it};
            ++it;
            auto right = term(tokens, it);
            if (right == nullptr) {
                return nullptr;
            }

            return Calc::Node::CreateBinaryOperator(op_str, left, right);
        } else {
            break;
        }
    }

    return left;
}

static std::shared_ptr<Node> expr(
    const std::vector<std::string>& tokens,
    std::vector<std::string>::const_iterator& it) {
    auto left = term(tokens, it);
    if (left == nullptr) {
        return nullptr;
    }

    while (it != tokens.end()) {
        if ((*it == "+") || (*it == "-")) {
            auto op_str{*it};
            ++it;
            auto right = expr(tokens, it);
            if (right == nullptr) {
                return nullptr;
            }

            return Calc::Node::CreateBinaryOperator(op_str, left, right);
        } else {
            break;
        }
    }

    return left;
}

std::shared_ptr<Node> Parser::parse(const std::vector<std::string>& tokens) {
    if (tokens.empty()) {
        return nullptr;
    }

    std::vector<std::string>::const_iterator it{tokens.begin()};
    return expr(tokens, it);
}

}  // namespace Calc
