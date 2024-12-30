#include "gtest/gtest.h"
#include "node.hpp"

TEST(NodeTest, CreateNumber) {
    auto n = Calc::Node(1);

    EXPECT_EQ(true, n.isNumber());
    EXPECT_EQ(1, n.eval());
}

TEST(NodeTest, OnePlusTwo) {
    auto a = std::make_unique<Calc::Node>(1);
    auto b = std::make_unique<Calc::Node>(2);
    auto c = Calc::Node(Calc::NodeType::ADD);
    c.appendLeft(a);
    c.appendRight(b);

    EXPECT_EQ(true, c.isOperator());
    EXPECT_EQ(1, c.left()->eval());
    EXPECT_EQ(2, c.right()->eval());
    EXPECT_EQ(3, c.eval());
}

TEST(NodeTest, OneMinusTwo) {
    auto a = std::make_unique<Calc::Node>(1);
    auto b = std::make_unique<Calc::Node>(2);
    auto c = Calc::Node(Calc::NodeType::SUB);
    c.appendLeft(a);
    c.appendRight(b);

    EXPECT_EQ(true, c.isOperator());
    EXPECT_EQ(1, c.left()->eval());
    EXPECT_EQ(2, c.right()->eval());
    EXPECT_EQ(-1, c.eval());
}

TEST(NodeTest, OneTimesTwo) {
    auto a = std::make_unique<Calc::Node>(1);
    auto b = std::make_unique<Calc::Node>(2);
    auto c = Calc::Node(Calc::NodeType::MUL);
    c.appendLeft(a);
    c.appendRight(b);

    EXPECT_EQ(true, c.isOperator());
    EXPECT_EQ(1, c.left()->eval());
    EXPECT_EQ(2, c.right()->eval());
    EXPECT_EQ(2, c.eval());
}

TEST(NodeTest, OneDividedByTwo) {
    auto a = std::make_unique<Calc::Node>(1);
    auto b = std::make_unique<Calc::Node>(2);
    auto c = Calc::Node(Calc::NodeType::DIV);
    c.appendLeft(a);
    c.appendRight(b);

    EXPECT_EQ(true, c.isOperator());
    EXPECT_EQ(1, c.left()->eval());
    EXPECT_EQ(2, c.right()->eval());
    EXPECT_EQ(0.5, c.eval());
}

TEST(NodeTest, OnePlusTwoMinusThree) {
    auto a = std::make_unique<Calc::Node>(1);
    auto b = std::make_unique<Calc::Node>(2);
    auto add = std::make_unique<Calc::Node>(Calc::NodeType::ADD);
    add->appendLeft(a);
    add->appendRight(b);

    auto c = std::make_unique<Calc::Node>(3);
    auto sub = Calc::Node(Calc::NodeType::SUB);
    sub.appendLeft(add);
    sub.appendRight(c);

    EXPECT_EQ(0, sub.eval());

    EXPECT_EQ(true, sub.left()->isOperator());
    EXPECT_EQ(1, sub.left()->left()->eval());
    EXPECT_EQ(2, sub.left()->right()->eval());
    EXPECT_EQ(3, sub.left()->eval());
}
