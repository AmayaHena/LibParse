/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** xmlParser
*/

#pragma once

    #include "File.hpp"

    #include <iostream>
    #include <vector>

namespace FormatParser {

    class xmlParser {

        public:

            /* Parse XML all Data */
            std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f);
            std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v);

        private:

            /* Parsing tools */
            std::string getLValue(std::string &s);
            std::string getRValue(std::vector<std::string> v, size_t i);

            /* XML Parsing Core */
            std::vector<std::pair<std::string, std::string>> parseAD(std::vector<std::string> v);

    };

}