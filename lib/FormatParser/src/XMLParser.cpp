/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** XMLParser
*/

#include "XMLParser.hpp"

namespace FormatParser {

    /* PRIVATE METHODS */

    std::string XMLParser::getString(const std::string &s, const char b, const char e) const
    {
        size_t ft = s.find(b) + 1;

        return s.substr(ft, s.find(e, ft) - ft);
    }

    char XMLParser::getCNb(const std::string s, char c) const
    {
        char it = 0;

        for (char a : s)
            if (a == c)
                it++;
        return it;
    }

    void XMLParser::makePair(const std::string &s, std::vector<std::pair<std::string, std::string>> &r) const
    {
        if (s.find("</") != std::string::npos
        && getCNb(s, '<') == 2 && getCNb(s, '>') == 2)
            r.push_back(make_pair(getLValue(s), getRValue(s)));
    }

    std::vector<std::pair<std::string, std::string>> XMLParser::parseAll(const std::vector<std::string> &v) const
    {
        std::vector<std::pair<std::string, std::string>> r;

        for (const std::string &s : v)
            makePair(s, r);
        return r;
    }

    std::vector<std::pair<std::string, std::string>> XMLParser::parseSection(const std::vector<std::string> &v, const std::string &match) const noexcept
    {
        std::vector<std::pair<std::string, std::string>> r;

        if (match.empty())
            return r;

        size_t it = 0;

        while (it < v.size())
            if (v[it++].find("<" + match + ">") != std::string::npos)
                break;
        if (it == v.size())
            return r;

        while (v[it] != "<" + match + "/>")
            makePair(v[it++], r);
        return r;
    }

    std::string XMLParser::parseValue(const std::vector<std::string> &v, const std::string &match) const noexcept
    {
        if (match.empty())
            return "";

        for (const std::string &s : v)
            if (s.find("<" + match + ">") != std::string::npos)
                return getRValue(s);
        return "";
    }

    std::vector<std::string> XMLParser::getSName(const std::vector<std::string> &v) const
    {
        std::vector<std::string> r;

        for (const std::string &s : v)
            if (s.find("/") == std::string::npos
        && getCNb(s, '<') == 1 && getCNb(s, '>') == 1)
                r.push_back(getLValue(s));
        return r;
    }

}
