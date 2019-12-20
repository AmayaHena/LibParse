/*
** EPITECH PROJECT, 2019
** LibParse
** File description:
** jsonParser
*/

#include "jsonParser.hpp"

namespace formatParser {

    std::vector<std::pair<std::string, std::string>> jsonParser::parse(fileManager::File f) { return parseAD(f.getContent()); }

    std::vector<std::pair<std::string, std::string>> jsonParser::parse(std::vector<std::string> v) { return parseAD(v); }

    std::vector<std::pair<std::string, std::string>> jsonParser::parse(fileManager::File f, std::string match) { return parseS(f.getContent(), match); }

    std::vector<std::pair<std::string, std::string>> jsonParser::parse(std::vector<std::string> v, std::string match) { return parseS(v, match); }

    std::string jsonParser::parseOne(fileManager::File f, std::string match) { return parseO(f.getContent(), match); }

    std::string jsonParser::parseOne(std::vector<std::string> v, std::string match) { return parseO(v, match); }

    std::string jsonParser::getLValue(const std::string s)
    {
        std::string rez;
        return rez;
    }

    std::string jsonParser::getRValue(const std::string s)
    {
        std::string rez;
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> m;

        if (v.empty())
            return m;
        return m;
    }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::vector<std::pair<std::string, std::string>> m;

        if (v.empty() || match.empty())
            return m;
        return m;
    }

    std::string jsonParser::parseO(std::vector<std::string> v, std::string match)
    {
        std::string rez;

        if (v.empty() || match.empty())
            return rez;
        for (const std::string &s : v)
            if (s.find(match))
                return getRValue(s);
        return rez;
    }

}