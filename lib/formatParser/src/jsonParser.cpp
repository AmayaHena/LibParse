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

    std::string jsonParser::getLValue(std::string s)
    {
        std::string rez;
        (void)s;
        return rez;
    }

    std::string jsonParser::getRValue(std::string s)
    {
        std::string rez;
        (void)s;
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty())
            return rez;
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty() || match.empty())
            return rez;

        unsigned int i = 0;

        while (i < v.size())
            if (v[i++].find("\"" + match + "\"") != std::string::npos)
                break;
        while (v[i++].find("}") != std::string::npos || i < v.size())
            rez.push_back(make_pair (getLValue(v[i]), getRValue(v[i])) );
        return rez;
    }

    std::string jsonParser::parseO(std::vector<std::string> v, std::string match)
    {
        std::string rez;

        if (v.empty() || match.empty())
            return rez;
        for (const std::string &s : v)
            if (s.find("\"" + match + "\"") != std::string::npos)
                return getRValue(s);
        return rez;
    }

}