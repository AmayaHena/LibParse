/*
** EPITECH PROJECT, 2019
** LibParse
** File description:
** xmlParser
*/

#include "xmlParser.hpp"

namespace formatParser {


    std::vector<std::pair<std::string, std::string>> xmlParser::parse(fileManager::File f) { return parseAD(f.getContent()); }

    std::vector<std::pair<std::string, std::string>> xmlParser::parse(std::vector<std::string> v) { return parseAD(v); }

    std::vector<std::pair<std::string, std::string>> xmlParser::parse(fileManager::File f, std::string match) { return parseS(f.getContent(), match); }

    std::vector<std::pair<std::string, std::string>> xmlParser::parse(std::vector<std::string> v, std::string match) { return parseS(v, match); }

    std::vector<std::pair<std::string, std::string>> xmlParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> rez;
        (void)v;
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> xmlParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::vector<std::pair<std::string, std::string>> rez;
        (void)v;
        (void)match;
        return rez;
    }

}
