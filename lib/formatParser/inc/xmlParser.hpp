/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** xmlParser
*/

#ifndef XMLPARSER_HPP_
#define XMLPARSER_HPP_

    #include "File.hpp"

    #include <iostream>
    #include <vector>

namespace formatParser {

    class xmlParser {

        public:

        /* Parse XML all Data */
        std::vector<std::pair<std::string, std::string>> parse(fileManager::File f);
        std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v);

        /* Parse XML all Data */
        std::vector<std::pair<std::string, std::string>> parse(fileManager::File f, std::string match);
        std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v, std::string match);

        private:

        /* Parsing tools */
        std::string getLValue(std::string s);
        std::string getRValue(std::vector<std::string> v, size_t i);

        /* XML Parsing Core */
        std::vector<std::pair<std::string, std::string>> parseAD(std::vector<std::string> v);
        std::vector<std::pair<std::string, std::string>> parseS(std::vector<std::string> v, std::string match);

    };

}

#endif /* !XMLPARSER_HPP_ */
