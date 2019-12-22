/*
** EPITECH PROJECT, 2019
** LibParse
** File description:
** jsonParser
*/

#ifndef JSONPARSER_HPP_
#define JSONPARSER_HPP_

    #include "File.hpp"

    #include <iostream>
    #include <vector>
    #include <unordered_map>

namespace formatParser {

    class jsonParser {

        public:

            /* Parse JSON all Data */
            std::vector<std::pair<std::string, std::string>> parse(fileManager::File f);
            std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v);

            /* Parse JSON with a section name */
            std::vector<std::pair<std::string, std::string>> parse(fileManager::File f, std::string match);
            std::vector<std::pair<std::string, std::string>> parse(std::vector<std::string> v, std::string match);

            /* Parse JSON for one data */
            std::string parseOne(fileManager::File f, std::string match);
            std::string parseOne(std::vector<std::string> v, std::string match);

        private:

            /* JSON Parsing Tools */
            std::string getLValue(std::string s);
            std::string getRValue(std::string s);

            /* JSON Parsing Core */
            std::vector<std::pair<std::string, std::string>> parseAD(std::vector<std::string> v);
            std::vector<std::pair<std::string, std::string>> parseS(std::vector<std::string> v, std::string match);
            std::string parseO(std::vector<std::string> v, std::string match);

    };

}

#endif /* !JSONPARSER_HPP_ */
