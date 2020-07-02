/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** JSONParser
*/

#pragma once

    #include "File.hpp"

    #include <iostream>
    #include <vector>

namespace FormatParser {

    class JSONParser final {

        public:

            /* Parse JSON all Data */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f) { return parseAD(f.getContent()); }
            inline std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> &v) { return parseAD(v); }

            /* Parse JSON with a section name */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f, const std::string &match) { return parseS(f.getContent(), match); }
            inline std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v, const std::string &match) { return parseS(v, match); }

            /* Parse JSON for one data */
            inline std::string parseRV(FileManager::File &f, const std::string &match) { return parseO(f.getContent(), match); }
            inline std::string parseRV(std::vector<std::string> &v, const std::string &match) { return parseO(v, match); }

            /* Get all section name */
            inline std::vector<std::string> getSection(FileManager::File &f) { return getSName(f.getContent()); }
            inline std::vector<std::string> getSection(std::vector<std::string> &v) { return getSName(v); }

        private:

            /* JSON Parsing Tools */
            std::string getLValue(std::string s);
            std::string getRValue(std::string s);

            /* JSON Parsing Core */
            std::vector<std::pair<std::string, std::string>> parseAD(const std::vector<std::string> &v);
            std::vector<std::pair<std::string, std::string>> parseS(const std::vector<std::string> &v, const std::string &match);
            std::string parseO(const std::vector<std::string> &v, const std::string &match);

            /* Get Section Name */
            std::vector<std::string> getSName(const std::vector<std::string> &v);

    };

}
