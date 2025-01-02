#ifndef PARSER_HPP
#define PARSER_HPP

#include <memory>
#include <string>
#include <vector>

#include "node.hpp"

namespace Calc {

class Parser {
public:
    Parser(){};

    ~Parser(){};

    std::shared_ptr<Node> parse(const std::vector<std::string>& tokens);
};

}  // namespace Calc

#endif
