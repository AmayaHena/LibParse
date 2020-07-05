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

    size_t JSONParser::makePair(const std::vector<std::string> &v, std::vector<std::pair<std::string, std::string>> &r, size_t it)
    {
        if (v[it].find("[") != std::string::npos && v[it].find("]") == std::string::npos) {
            const std::string s = getLValue(v[it]);
            while (v[it++].find("]") == std::string::npos)
                r.push_back(make_pair(s, getRValue(v[it])));
            return it;
        }

        else if (v[it].find("{") == std::string::npos && v[it].find("}") == std::string::npos
        && !v[it].empty())
            r.push_back(make_pair(getLValue(v[it]), getRValue(v[it])));
        return it;
    }

    std::vector<std::pair<std::string, std::string>> JSONParser::parseAD(const std::vector<std::string> &v)
    {
        std::vector<std::pair<std::string, std::string>> r;

        if (v.empty())
            return r;

        for (size_t it = 0; it < v.size(); it++)
            it = makePair(v, r, it);
        return r;
    }

    std::vector<std::pair<std::string, std::string>> JSONParser::parseS(const std::vector<std::string> &v, const std::string &match)
    {
        std::vector<std::pair<std::string, std::string>> r;

        if (v.empty() || match.empty())
            return r;

        size_t it = 0;

        while (it < v.size())
            if (v[it++].find("\"" + match + "\": {") != std::string::npos)
                break;
        if (it == v.size())
            return r;

        for (size_t j = 1; j > 0; it++) {
            if (v[it].find("{") != std::string::npos)
                j++;
            else if (v[it].find("}") != std::string::npos)
                j--;

            it = makePair(v, r, it);
        }
        return r;
    }

    std::string JSONParser::parseO(const std::vector<std::string> &v, const std::string &match)
    {
        if (v.empty() || match.empty())
            return "";

        for (const std::string &s : v)
            if (s.find("\"" + match + "\"") != std::string::npos)
                return getRValue(s);
        return "";
    }

    std::vector<std::string> JSONParser::getSName(const std::vector<std::string> &v)
    {
        std::vector<std::string> r;

        if (v.empty())
            return r;

        for (const std::string &s : v)
            if (s.find("{") != std::string::npos
            && s.size() > 1)
                r.push_back(getLValue(s));
        return r;
    }

}
