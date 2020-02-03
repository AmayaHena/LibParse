/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** basicConv
*/

#ifndef BASICCONV_HPP_
#define BASICCONV_HPP_

    #include <iostream>
    #include <vector>

namespace typeConv {

    class basicConv {

        public:

            std::string vToS(std::vector<std::string> v);
            std::vector<std::string> sToV(std::string s);

    };
}

#endif /* !BASICCONV_HPP_ */
