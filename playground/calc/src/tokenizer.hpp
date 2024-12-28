#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

namespace Calc {

class Tokenizer {
public:
    Tokenizer(std::vector<char>& separators) : separators_(separators) {}

    std::vector<std::string> tokenize(std::string str);

private:
    std::vector<char>& separators_;

    bool isSeparator(const char c);
};

}  // namespace Calc

#endif
