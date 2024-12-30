#include "expression.hpp"
#include "gtest/gtest.h"
#include "node.hpp"
#include "tokenizer.hpp"

static std::unique_ptr<Calc::Node> createAdd(const double a, const double b) {
    auto n_a = std::make_unique<Calc::Node>(a);
    auto n_b = std::make_unique<Calc::Node>(b);
    auto c = std::make_unique<Calc::Node>(Calc::NodeType::ADD);
    c->appendLeft(n_a);
    c->appendRight(n_b);

    return c;
}

TEST(ExpressionTest, EvaluateOnePlusTwo) {
    auto root = createAdd(1, 2);
    auto expr = Calc::Expression(root);

    EXPECT_EQ(3, expr.eval());
}

TEST(ExpressionTest, CreateOnePlusTwoMinusThree) {
    std::string str{"1+2-3"};
    auto expr = Calc::createExpression(str);

    EXPECT_EQ(0, expr.eval());
}
