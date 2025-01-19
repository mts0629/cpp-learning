#include "gtest/gtest.h"
#include "tokenizer.hpp"

class TokenizerTest : public ::testing::Test {
protected:
    std::unique_ptr<Calc::Tokenizer> tokenizer_;

    virtual void SetUp() { tokenizer_ = std::make_unique<Calc::Tokenizer>(); }

    virtual void TearDown() {}
};

TEST_F(TokenizerTest, TokenizeBySpace) {
    EXPECT_EQ((std::vector<std::string>{"1", "+", "2"}),
              tokenizer_->tokenize("1 + 2"));
}

TEST_F(TokenizerTest, TokenizeByTab) {
    EXPECT_EQ((std::vector<std::string>{"1", "+", "2"}),
              tokenizer_->tokenize("1\t+\t2"));
}

TEST_F(TokenizerTest, TokenizeByPredefinedSymbols) {
    EXPECT_EQ(
        (std::vector<std::string>{"1", "+", "2", "-", "3", "*", "4", "/", "5"}),
        tokenizer_->tokenize("1+2-3*4/5"));
}

TEST_F(TokenizerTest, TokenizeMultipleDigits) {
    EXPECT_EQ((std::vector<std::string>{"10", "+", "200"}),
              tokenizer_->tokenize("10+200"));
}

TEST_F(TokenizerTest, IgnoreLeadingAndTrailingSeparator) {
    EXPECT_EQ((std::vector<std::string>{"1", "+", "2"}),
              tokenizer_->tokenize(" 1 + 2 "));
}

TEST_F(TokenizerTest, IgnoreConsecuitiveSeparators) {
    EXPECT_EQ((std::vector<std::string>{"1", "+", "2"}),
              tokenizer_->tokenize("1  +   2"));
}

TEST_F(TokenizerTest, TokenizeNumberWithDecimalPoint) {
    EXPECT_EQ((std::vector<std::string>{"3.14"}), tokenizer_->tokenize("3.14"));
}

TEST_F(TokenizerTest, TokenizeNumberOnlyWithFractionalPart) {
    EXPECT_EQ((std::vector<std::string>{"3.00", "+", ".14"}),
              tokenizer_->tokenize("3.00+.14"));
}

TEST_F(TokenizerTest, TokenizeNumberOnlyWithIntegerPart) {
    EXPECT_EQ((std::vector<std::string>{"3.", "+", "0.14"}),
              tokenizer_->tokenize("3.+0.14"));
}

TEST_F(TokenizerTest, TokenizeParentheses) {
    EXPECT_EQ((std::vector<std::string>{"(", "1", "+", "2", ")", "*", "(", "3",
                                        "+", "4", ")"}),
              tokenizer_->tokenize("(1+2)*(3+4)"));
}

TEST_F(TokenizerTest, TokenizeAssignment) {
    EXPECT_EQ((std::vector<std::string>{"x", "=", "10"}),
              tokenizer_->tokenize("x=10"));
}

TEST_F(TokenizerTest, TokenizeVariableAndOperator) {
    EXPECT_EQ((std::vector<std::string>{"x", "+", "10"}),
              tokenizer_->tokenize("x+10"));
}

TEST_F(TokenizerTest, ReturnEmptyVectorWhenEmptyStringIsInput) {
    std::vector<std::string> empty{};
    EXPECT_EQ(empty, tokenizer_->tokenize(""));
}
