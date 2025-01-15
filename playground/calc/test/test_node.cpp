#include "gtest/gtest.h"
#include "node.hpp"

TEST(NodeTest, CreateNumber) {
    auto node = Calc::Node::CreateNumber("3.14");

    EXPECT_EQ(Calc::NodeType::Number, node->type());
    EXPECT_EQ(3.14, node->eval());
}

TEST(NodeTest, TokenIsInvalid) {
    ::testing::internal::CaptureStderr();
    auto node = Calc::Node::CreateNumber("???");

    EXPECT_EQ(nullptr, node);
    ASSERT_STREQ("[Error] invalid token: \"???\"\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, ValueIsOutOfRange) {
    ::testing::internal::CaptureStderr();
    auto node = Calc::Node::CreateNumber("1e+309");

    EXPECT_EQ(nullptr, node);
    ASSERT_STREQ("[Error] value 1e+309 is out of range of `double`\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, OnePlusTwo) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto node = Calc::Node::CreateBinaryOperator("+", a, b);

    EXPECT_EQ(Calc::NodeType::Add, node->type());
    EXPECT_EQ(1, node->left()->eval());
    EXPECT_EQ(2, node->right()->eval());
    EXPECT_EQ(3, node->eval());
}

TEST(NodeTest, OneMinusTwo) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto node = Calc::Node::CreateBinaryOperator("-", a, b);

    EXPECT_EQ(Calc::NodeType::Sub, node->type());
    EXPECT_EQ(1, node->left()->eval());
    EXPECT_EQ(2, node->right()->eval());
    EXPECT_EQ(-1, node->eval());
}

TEST(NodeTest, OneTimesTwo) {
    auto a = Calc::Node::CreateNumber("3.14");
    auto b = Calc::Node::CreateNumber("2");
    auto node = Calc::Node::CreateBinaryOperator("*", a, b);

    EXPECT_EQ(Calc::NodeType::Mul, node->type());
    EXPECT_EQ(3.14, node->left()->eval());
    EXPECT_EQ(2, node->right()->eval());
    EXPECT_EQ(6.28, node->eval());
}

TEST(NodeTest, OneDividedByTwo) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto node = Calc::Node::CreateBinaryOperator("/", a, b);

    EXPECT_EQ(Calc::NodeType::Div, node->type());
    EXPECT_EQ(1, node->left()->eval());
    EXPECT_EQ(2, node->right()->eval());
    EXPECT_EQ(0.5, node->eval());
}

TEST(NodeTest, OnePlusTwoMinusThree) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto a_plus_b = Calc::Node::CreateBinaryOperator("+", a, b);
    auto c = Calc::Node::CreateNumber("3");
    auto node = Calc::Node::CreateBinaryOperator("-", a_plus_b, c);

    EXPECT_EQ(0, node->eval());

    auto left = node->left();
    EXPECT_EQ(1, left->left()->eval());
    EXPECT_EQ(2, left->right()->eval());
    EXPECT_EQ(3, left->eval());
}

TEST(NodeTest, OnePlusTwoTimesThree) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto c = Calc::Node::CreateNumber("3");
    auto b_times_c = Calc::Node::CreateBinaryOperator("*", b, c);
    auto node = Calc::Node::CreateBinaryOperator("+", a, b_times_c);

    EXPECT_EQ(7, node->eval());

    auto right = node->right();
    EXPECT_EQ(2, right->left()->eval());
    EXPECT_EQ(3, right->right()->eval());
    EXPECT_EQ(6, right->eval());
}

TEST(NodeTest, OnePlusTwoFirstly_AndThenItTimesThree) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");
    auto c = Calc::Node::CreateNumber("3");
    auto a_plus_b = Calc::Node::CreateBinaryOperator("+", a, b);
    auto node = Calc::Node::CreateBinaryOperator("*", a_plus_b, c);

    EXPECT_EQ(9, node->eval());

    auto left = node->left();
    EXPECT_EQ(1, left->left()->eval());
    EXPECT_EQ(2, left->right()->eval());
    EXPECT_EQ(3, left->eval());
}

TEST(NodeTest, InvalidOperator) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");

    ::testing::internal::CaptureStderr();
    auto node = Calc::Node::CreateBinaryOperator("?", a, b);

    EXPECT_EQ(nullptr, node);
    ASSERT_STREQ("[Error] invalid token: \"?\"\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, EvaluateInvalidOperator) {
    auto a = Calc::Node::CreateNumber("1");
    auto b = Calc::Node::CreateNumber("2");

    ::testing::internal::CaptureStderr();
    Calc::Node node(Calc::NodeType::Invalid, a, b);

    EXPECT_EQ(std::numeric_limits<double>::infinity(), node.eval());
    ASSERT_STREQ("[Error] invalid operator\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, EvaluateBinaryOperatorWithoutLhs) {
    std::shared_ptr<Calc::Node> a{nullptr};
    auto b = Calc::Node::CreateNumber("2");

    ::testing::internal::CaptureStderr();
    auto node = Calc::Node::CreateBinaryOperator("*", a, b);

    EXPECT_EQ(std::numeric_limits<double>::infinity(), node->eval());
    ASSERT_STREQ("[Error] operand is lacking\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, EvaluateBinaryOperatorWithoutRhs) {
    auto a = Calc::Node::CreateNumber("1");
    std::shared_ptr<Calc::Node> b{nullptr};

    ::testing::internal::CaptureStderr();
    auto node = Calc::Node::CreateBinaryOperator("+", a, b);

    EXPECT_EQ(std::numeric_limits<double>::infinity(), node->eval());
    ASSERT_STREQ("[Error] operand is lacking\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST(NodeTest, EvaluateMinusOne) {
    auto a = Calc::Node::CreateNumber("1");

    auto node = Calc::Node::CreateUnaryOperator("-", a);

    EXPECT_EQ(-1, node->eval());
}

TEST(NodeTest, EvaluatePlusOne) {
    auto a = Calc::Node::CreateNumber("1");

    auto node = Calc::Node::CreateUnaryOperator("+", a);

    EXPECT_EQ(1, node->eval());
}
