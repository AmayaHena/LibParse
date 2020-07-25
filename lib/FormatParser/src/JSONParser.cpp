/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** JSONParser
*/

#include "JSONParser.hpp"

namespace FormatParser {

    /* PRIVATE METHODS */

    std::string JSONParser::getString(const std::string &s, const size_t i, bool last) const
    {
        size_t ft = s.find("\"", i) + 1;

        if (last)
            return s.substr(ft, s.find_last_of("\"")  - ft);
        return s.substr(ft, s.find("\"", ft) - ft);
    }

    std::string JSONParser::getRVNoStr(const std::string &s) const
    {
        if (s.find(":", s.find_last_of("\"")) == s.size() - 1)
            return "";

        size_t ft = s.find_first_not_of(" ", s.find_first_of(":") + 1);

        if (s.find(",") != std::string::npos)
            return s.substr(ft, s.find(",", ft) - ft);
        return s.substr(ft, s.size() - ft);
    }

    void JSONParser::makePair(const std::string &s, std::vector<std::pair<std::string, std::string>> &r) const
    {
        if (s.find("{") == std::string::npos
        && s.find("}") == std::string::npos
        && !s.empty()) {
            if (s.find("\"", s.find(":") + 1) == std::string::npos)
                r.push_back(make_pair(getLValue(s), getRVNoStr(s)));
            else
                r.push_back(make_pair(getLValue(s), getRValue(s)));
        }
    }

    std::vector<std::pair<std::string, std::string>> JSONParser::parseAll(const std::vector<std::string> &v) const
    {
        std::vector<std::pair<std::string, std::string>> r;

        for (const std::string &s : v)
            makePair(s, r);
        return r;
    }

    std::vector<std::pair<std::string, std::string>> JSONParser::parseSection(const std::vector<std::string> &v, const std::string &match) const noexcept
    {
        std::vector<std::pair<std::string, std::string>> r;

        if (match.empty())
            return r;

        size_t it = 0;

        while (it < v.size())
            if (v[it++].find("\"" + match + "\": {") != std::string::npos)
                break;
        if (it == v.size())
            return r;

        for (size_t ob = 1; ob > 0; it++) {
            if (v[it].find("{") != std::string::npos)
                ob++;
            else if (v[it].find("}") != std::string::npos)
                ob--;
            else
                makePair(v[it], r);
        }
        return r;
    }

    std::string JSONParser::parseValue(const std::vector<std::string> &v, const std::string &match) const noexcept
    {
        if (match.empty())
            return "";

        for (const std::string &s : v)
            if (s.find("\"" + match + "\"") != std::string::npos)
                return getRValue(s);
        return "";
    }

    std::vector<std::string> JSONParser::getSName(const std::vector<std::string> &v) const
    {
        std::vector<std::string> r;

        for (const std::string &s : v)
            if (s.find("{") != std::string::npos
            && s.size() > 1)
                r.push_back(getLValue(s));
        return r;
    }

}
