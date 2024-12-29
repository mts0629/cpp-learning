#include "gtest/gtest.h"
#include "tokenizer.hpp"

TEST(TokenizerTest, Tokenize) {
    auto separators = std::vector<char>{' '};
    auto tokenizer = Calc::Tokenizer(separators);

    EXPECT_EQ((std::vector<std::string>{"hello", "world"}),
              tokenizer.tokenize("hello world"));
}

TEST(TokenizerTest, NotTokenizeWhenNoSeparator) {
    auto separators = std::vector<char>{' '};
    auto tokenizer = Calc::Tokenizer(separators);

    EXPECT_EQ((std::vector<std::string>{"hello_world"}),
              tokenizer.tokenize("hello_world"));
}

TEST(TokenizerTest, IgnoreLeadingAndTrailingSeparator) {
    auto separators = std::vector<char>{' '};
    auto tokenizer = Calc::Tokenizer(separators);

    EXPECT_EQ((std::vector<std::string>{"hello", "world"}),
              tokenizer.tokenize("hello world "));
}

TEST(TokenizerTest, IgnoreConsecuitiveSeparators) {
    auto separators = std::vector<char>{' '};
    auto tokenizer = Calc::Tokenizer(separators);

    EXPECT_EQ((std::vector<std::string>{"hello", "world"}),
              tokenizer.tokenize("hello  world"));
}

TEST(TokenizerTest, TokenizeByMultipleSeparators) {
    auto separators = std::vector<char>{' ', '_'};
    auto tokenizer = Calc::Tokenizer(separators);

    EXPECT_EQ((std::vector<std::string>{"hello", "good", "world"}),
              tokenizer.tokenize("hello good_world"));
}
