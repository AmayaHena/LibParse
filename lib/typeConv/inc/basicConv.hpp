/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** basicConv
*/

#pragma once

    #include <iostream>
    #include <vector>

namespace typeConv {

    class basicConv {

        public:

            std::string vToS(std::vector<std::string> &v);
            std::vector<std::string> sToV(const std::string &s, char c = ' ');

    };

}
