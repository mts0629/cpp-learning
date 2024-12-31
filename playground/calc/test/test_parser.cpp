#include <memory>
#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "node.hpp"
#include "parser.hpp"

class ParserTest : public ::testing::Test {
protected:
    virtual void SetUp() { parser_ = std::make_unique<Calc::Parser>(); }

    virtual void TearDown() {}

    std::unique_ptr<Calc::Parser> parser_;

    template <class... T>
    std::vector<std::string> createTokens(T... tokens) {
        return std::vector<std::string>{tokens...};
    }
};

TEST_F(ParserTest, EvaluateOnePlusTwo) {
    auto tokens = createTokens("1", "+", "2");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(3, expr->eval());
}

TEST_F(ParserTest, CreateOnePlusTwoMinusThree) {
    auto tokens = createTokens("1", "+", "2", "-", "3");
    auto expr = parser_->parse(tokens);

    EXPECT_EQ(0, expr->eval());
}
