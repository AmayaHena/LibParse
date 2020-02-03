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

    std::string basicConv::vToS(std::vector<std::string> v)
    {
        std::string s;

        for (std::string &str: v)
            s += str;
        return s;
    }

    std::vector<std::string> basicConv::sToV(std::string s)
    {
        std::stringstream sstream(s);
        std::istream_iterator<std::string> begin(sstream);
        std::istream_iterator<std::string> end;
        std::vector<std::string> vstrings(begin, end);

        return vstrings;
    }

}
