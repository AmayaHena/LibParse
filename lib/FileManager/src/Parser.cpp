/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** Parser
*/

#include "Parser.hpp"

namespace FileManager {

    /* PRIVATE METHOD */

    void Parser::trimLine(std::string &s) const
    {
        if (s[s.size() - 1] != ' ')
            return;

        for (size_t it = s.size(); static_cast<int>(it) >= 0; it--) {
            if (s[it] == ' ') {
                s.erase(it);
                if (s[it - 1] != ' ')
                    return;
            }
        }
    }

    std::vector<std::string> Parser::trimCont(std::vector<std::string> v) const noexcept
    {
        std::vector<std::string> r;

        for (std::string &s: v) {
            if (!s.empty()) {
                trimLine(s);
                if (!s.empty())
                    r.push_back(s);
            }
        }
        return r;
    }

    std::string Parser::findS(const std::string &s, const std::vector<std::string> &v, size_t i) const noexcept
    {
        if (s.empty())
            return "";

        while (i < v.size()) {
            if (v[i].find(s, 0) != std::string::npos)
                return v[i];
            i++;
        }
        return "";
    }

    std::string Parser::getRawString(const std::string &s, const char c, size_t i) const
    {
        size_t ft = s.find(c, i) + 1;

        return s.substr(ft, s.find(c, ft) - ft);
    }

}
