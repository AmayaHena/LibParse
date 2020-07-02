/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** JSONParser
*/

#include "JSONParser.hpp"

namespace FormatParser {

    /* PRIVATE METHODS */

    std::string JSONParser::getLValue(std::string s) { return s.substr(s.find_first_of("\"") + 1, s.find("\"", s.find("\"") + 1) - s.find_first_of("\"") - 1); }

    std::string JSONParser::getRValue(std::string s) { return s.substr(s.find("\"", s.find(":")) + 1, s.find_last_of("\"") - s.find("\"", s.find(":")) - 1); }

    std::vector<std::pair<std::string, std::string>> JSONParser::parseAD(const std::vector<std::string> &v)
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

    std::vector<std::pair<std::string, std::string>> JSONParser::parseS(const std::vector<std::string> &v, const std::string &match)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty() || match.empty())
            return rez;

        size_t i = 0;

        while (i < v.size())
            if (v[i++].find("\"" + match + "\": {") != std::string::npos)
                break;
        if (i == v.size())
            return rez;

        for (size_t j = 1; j > 0; i++) {
            std::string s = getLValue(v[i]);

            if (v[i].find("{") != std::string::npos)
                j++;
            if (v[i].find("}") != std::string::npos)
                j--;

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

    std::string JSONParser::parseO(const std::vector<std::string> &v, const std::string &match)
    {
        std::string rez;

        if (v.empty() || match.empty())
            return rez;
        for (const std::string &s : v)
            if (s.find("\"" + match + "\"") != std::string::npos)
                return getRValue(s);
        return rez;
    }

    std::vector<std::string> JSONParser::getSName(const std::vector<std::string> &v)
    {
        std::vector<std::string> rez;

        if (v.empty())
            return rez;
        for (const std::string &s : v)
            if (s.find("{") != std::string::npos
            && s.size() > 1)
                rez.push_back(getLValue(s));

        return rez;
    }

}
