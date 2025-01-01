#include "tokenizer.hpp"

#include <iostream>
#include <sstream>

namespace {

static std::vector<char> separators{' ', '\t'};
static std::vector<std::string> predefined_symbols{"+", "-", "*", "/"};

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

static bool isPredefinedSymbol(const std::string& str) {
    for (auto symbol : predefined_symbols) {
        if (str == symbol) {
            return true;
        }
    }
    return false;
}

static bool isNumberCharacter(const char c) {
    return isdigit(c) ? true : false;
}

bool isNumber(const std::string& str) {
    for (auto c : str) {
        if (!isNumberCharacter(c)) {
            return false;
        }
    }
    return true;
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
    std::ostringstream buf{};
    std::vector<std::string> tokens{};

    for (auto it = str.begin(); it != str.end(); ++it) {
        auto c = *it;

        // Tokenize the buffer when a separator is input
        if (isSeparator(c)) {
            tokenizeCurrentBuffer(tokens, buf);
            continue;
        }

        // Store a character when the buffer is empty
        if (isStreamEmpty(buf)) {
            buf << c;
            continue;
        }

        auto current_token = buf.str();

        // Tokenize the buffer when it's defined symbol
        if (isPredefinedSymbol(current_token)) {
            tokenizeCurrentBuffer(tokens, buf);
            // Tokenize the buffer when the character type is
            // changed between number and non-number
        } else if (isNumberCharacter(c)) {
            if (!isNumber(current_token)) {
                tokenizeCurrentBuffer(tokens, buf);
            }
        } else {
            if (isNumber(current_token)) {
                tokenizeCurrentBuffer(tokens, buf);
            }
        }

        // Store a character
        buf << c;
    }

    // Flush the last token
    tokenizeCurrentBuffer(tokens, buf);

    return tokens;
}

}  // namespace Calc
