/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** jsonParser
*/

#pragma once

    #include "File.hpp"

    #include <iostream>
    #include <vector>

namespace FormatParser {

    class jsonParser final {

        public:

            /* Parse JSON all Data */
            std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f);
            std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v);

            /* Parse JSON with a section name */
            std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f, std::string match);
            std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v, std::string match);

            /* Parse JSON for one data */
            std::string parseOne(FileManager::File &f, std::string match);
            std::string parseOne(std::vector<std::string> v, std::string match);

            /* Get all section name */
            std::vector<std::string> getSection(FileManager::File &f);
            std::vector<std::string> getSection(std::vector<std::string> v);

        private:

            /* JSON Parsing Tools */
            std::string getLValue(std::string s);
            std::string getRValue(std::string s);

            /* JSON Parsing Core */
            std::vector<std::pair<std::string, std::string>> parseAD(std::vector<std::string> v);
            std::vector<std::pair<std::string, std::string>> parseS(std::vector<std::string> v, std::string &match);
            std::string parseO(std::vector<std::string> v, std::string &match);

            /* Get Section Name */
            std::vector<std::string> getSName(std::vector<std::string> v);

    };

}
