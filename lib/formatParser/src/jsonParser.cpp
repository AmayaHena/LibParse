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

    std::string jsonParser::getLValue(std::string s) { return s.substr(s.find_first_of("\"") + 1, s.find("\"", s.find("\"") + 1) - s.find_first_of("\"") - 1); }

    std::string jsonParser::getRValue(std::string s) { return s.substr(s.find("\"", s.find(":")) + 1, s.find_last_of("\"") - s.find("\"", s.find(":")) - 1); }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty())
            return rez;
        for (size_t i = 0; i < v.size(); i++) {
            std::string s = getLValue(v[i]);

            if (v[i].find("[") != std::string::npos
            && v[i].find("]") == std::string::npos)
                while (v[i++].find("]") == std::string::npos)
                    rez.push_back(make_pair(s, getRValue(v[i])));

            if (v[i].find("{") == std::string::npos
            && v[i].find("}") == std::string::npos
            && !v[i].empty())
                rez.push_back(make_pair(s, getRValue(v[i])));
        }
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> jsonParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty() || match.empty())
            return rez;

        size_t i = 0;

        while (i < v.size())
            if (v[i++].find("\"" + match + "\": {") != std::string::npos)
                break;
        /* WARNING */
        /* ne parse une seule section et stop au premier { */
        /* compter le nomre de { = +1 & } = -1 */
        /* WARNING */
        while (v[i++].find("}") != std::string::npos || i < v.size())
            rez.push_back(make_pair(getLValue(v[i]), getRValue(v[i])));
        /* WARNING */
        return rez;
    }

    std::string jsonParser::parseO(std::vector<std::string> v, std::string match)
    {
        std::string rez;

        if (v.empty() || match.empty())
            return rez;
        for (const std::string &s : v)
            if (s.find("\"" + match + "\" : ") != std::string::npos)
                return getRValue(s);
        return rez;
    }

}