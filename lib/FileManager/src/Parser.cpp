/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** Parser
*/

#include "Parser.hpp"

namespace FileManager {

    /* PRIVATE METHOD */

    void Parser::cleanG(std::string &s)
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

    std::vector<std::string> Parser::cleanV(std::vector<std::string> v)
    {
        std::vector<std::string> r;

        for (std::string &s: v) {
            if (!s.empty()) {
                cleanG(s);
                if (!s.empty())
                    r.push_back(s);
            }
        }
        return r;
    }

    std::string Parser::findS(const std::string &s, const std::vector<std::string> &v, size_t i)
    {
        while (i < v.size()) {
            if (v[i].find(s, 0) != std::string::npos)
                return v[i];
            i++;
        }
        return "";
    }

}
