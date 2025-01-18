#include <memory>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "node.hpp"
#include "parser.hpp"

class ParserTest : public ::testing::Test {
protected:
    std::unique_ptr<Calc::Parser> parser_;

    virtual void SetUp() { parser_ = std::make_unique<Calc::Parser>(); }

    virtual void TearDown() {}

    template <class... T>
    std::vector<std::string> createTokens(T... tokens) {
        return std::vector<std::string>{tokens...};
    }
};

TEST_F(ParserTest, EvaluateOne) {
    auto tokens = createTokens("1");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(1, expr->eval());
}

TEST_F(ParserTest, EvaluatePi) {
    auto tokens = createTokens("3.14");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3.14, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwo) {
    auto tokens = createTokens("1", "+", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3, expr->eval());
}

TEST_F(ParserTest, EvaluateOneMinusTwo) {
    auto tokens = createTokens("1", "-", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(-1, expr->eval());
}

TEST_F(ParserTest, EvaluateOneTimesTwo) {
    auto tokens = createTokens("1", "*", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(2, expr->eval());
}

TEST_F(ParserTest, EvaluateOneDividedByTwo) {
    auto tokens = createTokens("1", "/", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(0.5, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwoMinusThree) {
    auto tokens = createTokens("1", "+", "2", "-", "3");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(0, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwoTimesThree) {
    auto tokens = createTokens("1", "+", "2", "*", "3");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(7, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwoDivideByThree) {
    auto tokens = createTokens("1", "+", "2", "/", "3");
    auto expr = parser_->parse(tokens);

    EXPECT_DOUBLE_EQ(1.666666666666666, expr->eval());
}

TEST_F(ParserTest, EvaluateOneTimesTwoPlusThree) {
    auto tokens = createTokens("1", "*", "2", "+", "3");
    auto expr = parser_->parse(tokens);

    EXPECT_DOUBLE_EQ(5, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwoTimesThreeTimesFour) {
    auto tokens = createTokens("1", "+", "2", "*", "3", "*", "4");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(25, expr->eval());
}

TEST_F(ParserTest, EvaluateOnePlusTwoTimesThreePlusFour) {
    auto tokens = createTokens("1", "+", "2", "*", "3", "+", "4");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(11, expr->eval());
}

TEST_F(ParserTest, EvaluateOneDividedByTwoPlusThreeTimesFour) {
    auto tokens = createTokens("1", "/", "2", "+", "3", "*", "4");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(12.5, expr->eval());
}

TEST_F(ParserTest, EvaluateParentheses) {
    auto tokens = createTokens("(", "1", "+", "2", ")", "*", "(", "3", "+", "4",
                               ")", "+", "5");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(26, expr->eval());
}

TEST_F(ParserTest, EvaluateNestedParentheses) {
    auto tokens = createTokens("(", "(", "1", "+", "2", ")", "*", "(", "3", "+",
                               "4", ")", ")", "*", "5");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(105, expr->eval());
}

TEST_F(ParserTest, EvaluateOnlyParenthesesTerm) {
    auto tokens = createTokens("(", "1", "+", "2", ")");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3, expr->eval());
}

TEST_F(ParserTest, EvaluateMinusOnePlusTwo) {
    auto tokens = createTokens("-", "1", "+", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(1, expr->eval());
}

TEST_F(ParserTest, EvaluatePlusOnePlusTwo) {
    auto tokens = createTokens("+", "1", "+", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3, expr->eval());
}

TEST_F(ParserTest, EvaluateMinusForParenthesesTerm) {
    auto tokens = createTokens("-", "(", "1", "+", "2", ")");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(-3, expr->eval());
}

TEST_F(ParserTest, EvaluateTwoTimesMinusOne) {
    auto tokens = createTokens("2", "*", "-", "1");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(-2, expr->eval());
}

TEST_F(ParserTest, EvaluateAssignOneToX) {
    auto tokens = createTokens("x", "=", "1");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(1, expr->eval());
}

TEST_F(ParserTest, EvaluateAssignOnePlusTwoToX) {
    auto tokens = createTokens("x", "=", "1", "+", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3, expr->eval());
}

TEST_F(ParserTest, ReturnNullptrWhenLhsIsInvalidToken) {
    auto tokens = createTokens("???", "+", "1");

    ::testing::internal::CaptureStderr();
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(nullptr, expr);
    ASSERT_STREQ("[Error] invalid token: \"???\"\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST_F(ParserTest, ReturnNullptrWhenRhsIsInvalidToken) {
    auto tokens = createTokens("1", "+", "???");

    ::testing::internal::CaptureStderr();
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(nullptr, expr);
    ASSERT_STREQ("[Error] invalid token: \"???\"\n",
                 ::testing::internal::GetCapturedStderr().c_str());
}

TEST_F(ParserTest, ReturnNullptrWhenTokensAreEmpty) {
    std::vector<std::string> tokens{};
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(nullptr, expr);
}
