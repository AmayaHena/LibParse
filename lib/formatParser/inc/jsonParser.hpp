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
            std::unordered_map<std::string, std::string> parse(fileManager::File f);
            std::unordered_map<std::string, std::string> parse(std::vector<std::string> v);

            /* Parse JSON with a section name */
            std::unordered_map<std::string, std::string> parse(fileManager::File f, std::string match);
            std::unordered_map<std::string, std::string> parse(std::vector<std::string> v, std::string match);

            /* Parse JSON for one data */
            std::string parseOne(fileManager::File f, std::string match);
            std::string parseOne(std::vector<std::string> v, std::string match);

        private:

    };

}

#endif /* !JSONPARSER_HPP_ */
