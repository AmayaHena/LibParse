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
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f) const { return parseAll(f.getContent()); }
            inline std::vector<std::pair<std::string, std::string>> parse(const std::vector<std::string> &v) const { return parseAll(v); }

        private:

            /* Parsing LV & RV */
            std::string getLValue(const std::string &s) const;
            std::string getRValue(const std::vector<std::string> &v, size_t i) const;

            /* Parsing */
            std::vector<std::pair<std::string, std::string>> parseAll(const std::vector<std::string> &v) const;

    };

}
