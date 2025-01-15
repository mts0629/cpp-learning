#include "tokenizer.hpp"

#include <iostream>
#include <sstream>

namespace {

static std::vector<char> separators{' ', '\t'};
static std::vector<std::string> defined_symbols{"+", "-", "*", "/", "(", ")"};

}  // namespace

namespace Calc {

static bool isSeparator(const char c) {
    for (auto separator : separators) {
        if (c == separator) {
            return true;
        }
    }
    return false;
}

static bool isDefinedSymbol(const std::string& str) {
    for (auto symbol : defined_symbols) {
        if (str == symbol) {
            return true;
        }
    }
    return false;
}

static bool isNumberCharacter(const char c) {
    return (isdigit(c) || c == '.') ? true : false;
}

static bool isNumberStart(const char prev_c, const char c) {
    return !isNumberCharacter(prev_c) && isNumberCharacter(c);
}

static bool isNumberFinished(const char prev_c, const char c) {
    return isNumberCharacter(prev_c) && !isNumberCharacter(c);
}

static bool isStreamEmpty(std::ostringstream& buf) {
    return buf.tellp() == std::streampos(0);
}

static void tokenizeCurrentBuffer(std::vector<std::string>& tokens,
                                  std::ostringstream& buf) {
    if (isStreamEmpty(buf)) {
        return;
    }

    tokens.push_back(buf.str());
    buf.str("");
}

std::vector<std::string> Tokenizer::tokenize(std::string str) {
    std::vector<std::string> tokens{};
    if (str.empty()) {
        return tokens;
    }

    std::ostringstream buf{};
    char prev_c = str[0];
    for (auto it = str.begin(); it != str.end(); ++it) {
        auto c = *it;

        // Tokenize the buffer when a separator is input
        if (isSeparator(c)) {
            tokenizeCurrentBuffer(tokens, buf);
            continue;
        }

        if (!isStreamEmpty(buf)) {
            auto current_token = buf.str();
            // Tokenize the buffer when it's defined symbol
            if (isDefinedSymbol(current_token)) {
                tokenizeCurrentBuffer(tokens, buf);
                // Tokenize the buffer when the character type is changed
                // between number and non-number
            } else if (isNumberStart(prev_c, c) ||
                       isNumberFinished(prev_c, c)) {
                tokenizeCurrentBuffer(tokens, buf);
            }
        }

        // Store the next character
        buf << c;
        prev_c = c;
    }

    // Flush the last token
    tokenizeCurrentBuffer(tokens, buf);

    return tokens;
}

}  // namespace Calc
