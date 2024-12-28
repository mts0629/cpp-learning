#include "tokenizer.hpp"

#include <sstream>

namespace Calc {

bool Tokenizer::isSeparator(const char c) {
    for (auto s : this->separators_) {
        if (c == s) {
            return true;
        }
    }

    return false;
}

static bool isStreamEmpty(std::ostringstream& buf) {
    return buf.tellp() == std::streampos(0);
}

static void flushCurrentToken(std::vector<std::string>& tokens,
                              std::ostringstream& buf) {
    tokens.push_back(buf.str());
    buf.str("");
}

std::vector<std::string> Tokenizer::tokenize(std::string str) {
    std::ostringstream buf{};
    std::vector<std::string> tokens{};

    for (auto it = str.begin(); it != str.end(); ++it) {
        auto c = *it;

        if (isSeparator(c)) {
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }
            if (!isspace(c)) {
                buf << c;
            }
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }

            continue;
        }

        buf << c;

        if (it == (str.end() - 1)) {
            if (!isStreamEmpty(buf)) {
                flushCurrentToken(tokens, buf);
            }
        }
    }

    return tokens;
}

}  // namespace Calc
