/*
** EPITECH PROJECT, 2019
** LibParse
** File description:
** jsonParser
*/

#include "jsonParser.hpp"

namespace formatParser {

    std::unordered_map<std::string, std::string> jsonParser::parse(fileManager::File f) { return parseAD(f.getContent()); }

    std::unordered_map<std::string, std::string> jsonParser::parse(std::vector<std::string> v) { return parseAD(v); }

    std::unordered_map<std::string, std::string> jsonParser::parse(fileManager::File f, std::string match) { return parseS(f.getContent(), match); }

    std::unordered_map<std::string, std::string> jsonParser::parse(std::vector<std::string> v, std::string match) { return parseS(v, match); }

    std::string jsonParser::parseOne(fileManager::File f, std::string match) { return parseO(f.getContent(), match); }

    std::string jsonParser::parseOne(std::vector<std::string> v, std::string match) { return parseO(v, match); }

    std::unordered_map<std::string, std::string> jsonParser::parseAD(std::vector<std::string> v)
    {
        std::unordered_map<std::string, std::string> m;

        if (v.empty())
            return m;
        return m;
    }

    std::unordered_map<std::string, std::string> jsonParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::unordered_map<std::string, std::string> m;

        if (v.empty() || match.empty())
            return m;
        return m;
    }

    std::string jsonParser::parseO(std::vector<std::string> v, std::string match)
    {
        std::string rez;

        if (v.empty() || match.empty())
            return rez;
        return rez;
    }

}