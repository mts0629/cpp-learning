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

TEST(NodeTest, CreateVariable) {
    std::vector<std::string> tokens = {"x", "var", "var1", "var_1"};

    for (auto token : tokens) {
        auto var = Calc::Node::CreateVariable(token);

        EXPECT_EQ(Calc::NodeType::Variable, var->type());

        ::testing::internal::CaptureStderr();
        EXPECT_EQ(std::numeric_limits<double>::infinity(), var->eval());
        auto error_message =
            "[Error] variable \"" + token + "\" is unassigned\n";
        ASSERT_STREQ(error_message.c_str(),
                     ::testing::internal::GetCapturedStderr().c_str());
    }
}

TEST(NodeTest, CannotCreateVariableInInvalidFormat) {
    std::vector<std::string> tokens = {"1", "1var", "+", "var+", "_var"};

    for (auto token : tokens) {
        ::testing::internal::CaptureStderr();
        auto var = Calc::Node::CreateVariable(token);

        EXPECT_EQ(nullptr, var);
        auto error_message =
            "[Error] variable \"" + token +
            "\" is invalid (format: `[a-zA-Z]+[a-zA-Z0-9]*`)\n";
        ASSERT_STREQ(error_message.c_str(),
                     ::testing::internal::GetCapturedStderr().c_str());
    }
}

TEST(NodeTest, AssignOneToX) {
    auto var = Calc::Node::CreateVariable("x");
    auto one = Calc::Node::CreateNumber("1");

    var->assign(one);

    EXPECT_EQ(1, var->eval());
}

TEST(NodeTest, AssignOnePlusTwo) {
    auto var = Calc::Node::CreateVariable("x");

    auto one = Calc::Node::CreateNumber("1");
    auto two = Calc::Node::CreateNumber("2");
    auto op = Calc::Node::CreateBinaryOperator("+", one, two);

    var->assign(op);

    EXPECT_EQ(3, var->eval());
}

TEST(NodeTest, CannotAssignToNonVariables) {
    auto a = Calc::Node::CreateNumber("-1");
    auto b = Calc::Node::CreateNumber("3");
    std::vector<std::shared_ptr<Calc::Node>> nodes = {
        Calc::Node::CreateNumber("2"),
        Calc::Node::CreateBinaryOperator("+", a, b)};

    auto one = Calc::Node::CreateNumber("1");

    for (auto node : nodes) {
        ::testing::internal::CaptureStderr();
        node->assign(one);

        EXPECT_EQ(2, node->eval());
        ASSERT_STREQ("[Error] only variables can be assigned\n",
                     ::testing::internal::GetCapturedStderr().c_str());
    }
}
