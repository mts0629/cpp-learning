#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <string>
#include <vector>

namespace Calc {

class Tokenizer {
public:
    Tokenizer(){};

    ~Tokenizer(){};

    std::vector<std::string> tokenize(std::string str);
};

}  // namespace Calc

#endif
