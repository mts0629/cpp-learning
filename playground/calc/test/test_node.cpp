#include "gtest/gtest.h"
#include "node.hpp"

TEST(NodeTest, CreateNumber) {
    Calc::Node n(1);

    EXPECT_EQ(Calc::NodeType::Number, n.type());
    EXPECT_EQ(1, n.eval());
}

TEST(NodeTest, OnePlusTwo) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto add = std::make_shared<Calc::Node>(Calc::NodeType::Add);
    add->attachLeft(a);
    add->attachRight(b);

    EXPECT_EQ(Calc::NodeType::Add, add->type());
    EXPECT_EQ(1, add->left()->eval());
    EXPECT_EQ(add, add->left()->parent());
    EXPECT_EQ(2, add->right()->eval());
    EXPECT_EQ(add, add->right()->parent());
    EXPECT_EQ(3, add->eval());
}

TEST(NodeTest, OneMinusTwo) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto sub = std::make_shared<Calc::Node>(Calc::NodeType::Sub);
    sub->attachLeft(a);
    sub->attachRight(b);

    EXPECT_EQ(Calc::NodeType::Sub, sub->type());
    EXPECT_EQ(1, sub->left()->eval());
    EXPECT_EQ(2, sub->right()->eval());
    EXPECT_EQ(-1, sub->eval());
}

TEST(NodeTest, OneTimesTwo) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto mul = std::make_shared<Calc::Node>(Calc::NodeType::Mul);
    mul->attachLeft(a);
    mul->attachRight(b);

    EXPECT_EQ(Calc::NodeType::Mul, mul->type());
    EXPECT_EQ(1, mul->left()->eval());
    EXPECT_EQ(2, mul->right()->eval());
    EXPECT_EQ(2, mul->eval());
}

TEST(NodeTest, OneDividedByTwo) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto div = std::make_shared<Calc::Node>(Calc::NodeType::Div);
    div->attachLeft(a);
    div->attachRight(b);

    EXPECT_EQ(Calc::NodeType::Div, div->type());
    EXPECT_EQ(1, div->left()->eval());
    EXPECT_EQ(2, div->right()->eval());
    EXPECT_EQ(0.5, div->eval());
}

TEST(NodeTest, OnePlusTwoMinusThree) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto add = std::make_shared<Calc::Node>(Calc::NodeType::Add);
    add->attachLeft(a);
    add->attachRight(b);

    auto c = std::make_shared<Calc::Node>(3);
    auto sub = std::make_shared<Calc::Node>(Calc::NodeType::Sub);
    sub->attachLeft(add);
    sub->attachRight(c);

    EXPECT_EQ(0, sub->eval());

    auto node = sub->left();
    EXPECT_EQ(sub, node->parent());
    EXPECT_EQ(1, node->left()->eval());
    EXPECT_EQ(2, node->right()->eval());
    EXPECT_EQ(3, node->eval());
}

TEST(NodeTest, OnePlusTwoTimesThree) {
    auto b = std::make_shared<Calc::Node>(2);
    auto c = std::make_shared<Calc::Node>(3);
    auto mul = std::make_shared<Calc::Node>(Calc::NodeType::Mul);
    mul->attachLeft(b);
    mul->attachRight(c);

    auto a = std::make_shared<Calc::Node>(1);
    auto add = std::make_shared<Calc::Node>(Calc::NodeType::Add);
    add->attachLeft(a);
    add->attachRight(mul);

    EXPECT_EQ(7, add->eval());

    EXPECT_EQ(add, add->left()->parent());
}

TEST(NodeTest, SwapLeft) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto add = std::make_shared<Calc::Node>(Calc::NodeType::Add);
    add->attachLeft(a);
    add->attachRight(b);

    auto c = std::make_shared<Calc::Node>(3);
    auto removed = add->swapLeft(c);

    EXPECT_EQ(1, removed->eval());
    EXPECT_EQ(3, add->left()->eval());
    EXPECT_EQ(5, add->eval());
}

TEST(NodeTest, SwapRight) {
    auto a = std::make_shared<Calc::Node>(1);
    auto b = std::make_shared<Calc::Node>(2);
    auto add = std::make_shared<Calc::Node>(Calc::NodeType::Add);
    add->attachLeft(a);
    add->attachRight(b);

    auto c = std::make_shared<Calc::Node>(3);
    auto removed = add->swapRight(c);

    EXPECT_EQ(2, removed->eval());
    EXPECT_EQ(3, add->right()->eval());
    EXPECT_EQ(4, add->eval());
}
