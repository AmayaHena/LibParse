/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** XMLParser
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include "File.hpp"

namespace FormatParser {

    class XMLParser final {

        public:

            XMLParser() = default;

            /* Parse */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f)  { return parseAD(f.getContent()); }
            inline std::vector<std::pair<std::string, std::string>> parse(const std::vector<std::string> &v)  { return parseAD(v); }

        private:

            /* Parsing LV & RV */
            std::string getLValue(const std::string &s);
            std::string getRValue(const std::vector<std::string> &v, size_t i);

            /* Parsing */
            std::vector<std::pair<std::string, std::string>> parseAD(const std::vector<std::string> &v);

    };

}
