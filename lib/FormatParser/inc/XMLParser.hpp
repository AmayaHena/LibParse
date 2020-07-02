/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** XMLParser
*/

#pragma once

    #include "File.hpp"

    #include <iostream>
    #include <vector>

namespace FormatParser {

    class XMLParser {

        public:

            XMLParser() = default;
            ~XMLParser() = default;

            /* Parse */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f)  { return parseAD(f.getContent()); }
            inline std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> &v)  { return parseAD(v); }

        private:

            /* Parsing LV & RV */
            std::string getLValue(std::string s);
            std::string getRValue(const std::vector<std::string> &v, size_t i);

            /* Parsing */
            std::vector<std::pair<std::string, std::string>> parseAD(const std::vector<std::string> &v);

    };

}
