#include "tokenizer.hpp"

#include <iostream>
#include <sstream>

namespace Calc {

static bool isSeparator(const char c) {
    static std::vector<char> separators{' ', '\t'};

    for (auto separator : separators) {
        if (c == separator) {
            return true;
        }
    }
    return false;
}

static bool isDefinedSymbol(const std::string& str) {
    static std::vector<std::string> defined_symbols{"+", "-", "*", "/",
                                                    "(", ")", "="};

    for (auto symbol : defined_symbols) {
        if (str == symbol) {
            return true;
        }
    }
    return false;
}

static bool isNumberCharacter(const char c) {
    return (isdigit(c) || (c == '.')) ? true : false;
}

static bool isIdentifierCharacter(const char c) {
    return (isalnum(c) || (c == '_')) ? true : false;
}

enum class CharType { Number, Identifier, Separators, Others };

static CharType getCurrentCharType(const CharType state, const char next) {
    if (isSeparator(next)) {
        return CharType::Separators;
    }

    if (state == CharType::Number) {
        if (isNumberCharacter(next)) {
            return state;
        } else if (isalpha(next)) {
            return CharType::Identifier;
        }
    } else if (state == CharType::Identifier) {
        if (isIdentifierCharacter(next)) {
            return state;
        }
    } else {  // CharType::Others
        if (isNumberCharacter(next)) {
            return CharType::Number;
        } else if (isalpha(next)) {
            return CharType::Identifier;
        }
    }

    return CharType::Others;
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
    CharType prev_char_type = CharType::Others;
    for (auto it = str.begin(); it != str.end(); ++it) {
        auto char_type = getCurrentCharType(prev_char_type, *it);

        // Tokenize the buffer when a separator is input
        if (char_type == CharType::Separators) {
            tokenizeCurrentBuffer(tokens, buf);
            prev_char_type = char_type;
            continue;
        }

        if (!isStreamEmpty(buf)) {
            // Tokenize the buffer when it's defined symbol
            if (isDefinedSymbol(buf.str())) {
                tokenizeCurrentBuffer(tokens, buf);
            } else {
                // Tokenize the buffer when the character type is changed
                if (char_type != prev_char_type) {
                    tokenizeCurrentBuffer(tokens, buf);
                }
            }
        }

        prev_char_type = char_type;

        // Store the next character
        buf << *it;
    }

    // Flush the last token
    tokenizeCurrentBuffer(tokens, buf);

    return tokens;
}

}  // namespace Calc
