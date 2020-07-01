/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** Parser
*/

#include "Parser.hpp"

namespace FileManager {

    /* PUBLIC METHOD */

    std::vector<std::string> Parser::clean(File &f) { return cleanV(f.getContent()); }

    std::vector<std::string> Parser::clean(std::vector<std::string> &v) { return cleanV(v); }

    std::string Parser::find(std::string s, File &f, size_t i) { return findS(s, f.getContent(), i); }

    std::string Parser::find(std::string s, std::vector<std::string> v, size_t i) { return findS(s, v, i); }

    /* PRIVATE METHOD */

    void Parser::cleanL(std::string &s)
    {
        if (s[s.size() - 1] != ' ')
            return;

        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == ' ') {
                s.erase(i);
                if (s[i - 1] != ' ')
                    return;
            }
        }
    }

    std::vector<std::string> Parser::cleanV(std::vector<std::string> v)
    {
        std::vector<std::string> r;

        for (std::string &s: v) {
            if (!s.empty()) {
                cleanL(s);
                if (!s.empty())
                    r.push_back(s);
            }
        }
        return r;
    }

    std::string Parser::findS(std::string &s, std::vector<std::string> v, size_t i)
    {
        std::string ec;

        while (i < v.size()) {
            if (v[i].find(s, 0) != std::string::npos)
                return v[i];
            i++;
        }
        return ec;
    }

}
