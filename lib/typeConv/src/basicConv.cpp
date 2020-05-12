/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** basicConv
*/

#include "basicConv.hpp"

#include <sstream>
#include <iterator>

namespace typeConv {

    std::string basicConv::vToS(std::vector<std::string> &v)
    {
        std::string s;

        for (std::string &str: v)
            s += str;
        return s;
    }

    std::vector<std::string> basicConv::sToV(const std::string &s, char c)
    {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(s);
        while (std::getline(tokenStream, token, c))
            tokens.push_back(token);
        return tokens;
    }

}
