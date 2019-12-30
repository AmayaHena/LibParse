/*
** PERSONAL PROJECT, 2019
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

    std::string xmlParser::getLValue(std::string s) { return s.substr(s.find_first_of("<") + 1, s.find("<", s.find("<") + 1) - s.find_first_of("<") - 1); }

    std::string xmlParser::getRValue(std::vector<std::string> v, size_t i)
    {
        std::string s;

        if (v[i].find("</") != std::string::npos) {
            // bad
            s = v[i].substr(v[i].find_first_of(">"), v[i].find_last_of("</"));
        } else {
            // bad
            s += v[i].substr(v[i].find_first_of(">"), v[i].size() - 1);
            while (v[i++].find("</") == std::string::npos)
                s += v[i];
            s += v[i].substr(0, v[i].find_first_of("<"));
        }

        return s;
    }

    std::vector<std::pair<std::string, std::string>> xmlParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty())
            return rez;

        for (size_t i = 0; i < v.size(); i++) {
            rez.push_back(make_pair(getLValue(v[i]), getRValue(v, i)));
            while (v[i++].find("</") == std::string::npos);
        }
        return rez;
    }

    std::vector<std::pair<std::string, std::string>> xmlParser::parseS(std::vector<std::string> v, std::string match)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty())
            return rez;

        size_t i = 0;

        while (v[i++].find("<" + match) == std::string::npos);

        while (i < v.size() || v[i++].find("</" + match + ">") == std::string::npos) {
            rez.push_back(make_pair(getLValue(v[i]), getRValue(v, i)));
            while (v[i++].find("</") == std::string::npos);
        }
        return rez;
    }

}
