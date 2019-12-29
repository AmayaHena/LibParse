/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** basicConv
*/

#include "basicConv.hpp"
namespace typeConv {

        std::string basicConv::vToS(std::vector<std::string> v)
        {
            std::string s;

            for (std::string &str: v)
                s += str;
            return s;
        }

}
