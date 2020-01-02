/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** xmlParser
*/

#include "xmlParser.hpp"

namespace formatParser {


    std::vector<std::pair<std::string, std::string>> xmlParser::parse(fileManager::File &f) { return parseAD(f.getContent()); }

    std::vector<std::pair<std::string, std::string>> xmlParser::parse(std::vector<std::string> v) { return parseAD(v); }

    std::string xmlParser::getLValue(std::string &s) { return s.substr(s.find_first_of("<") +1, s.find_first_of(">") -1); }

    std::string xmlParser::getRValue(std::vector<std::string> v, size_t i)
    {
        std::string s;

        if (v[i].find("</") != std::string::npos) {
            return v[i].substr(v[i].find_first_of(">") +1, v[i].find_last_of("<") - v[i].find_first_of(">") -1);
        } else {
            s += v[i].substr(v[i].find_first_of(">") +1, v[i].size() - 1);
            if (v[i + 1].find("</") != std::string::npos) {
                s += v[i + 1].substr(0, v[i + 1].find("</"));
                return s;
            }
            while (v[i++].find("</") == std::string::npos) {
                if (v[i].find("</") != std::string::npos)
                    break;
                s += v[i];
            }
        }

        return s;
    }

    std::vector<std::pair<std::string, std::string>> xmlParser::parseAD(std::vector<std::string> v)
    {
        std::vector<std::pair<std::string, std::string>> rez;

        if (v.empty())
            return rez;

        for (size_t i = 0; i < v.size(); i++) {
            if (!v[i].empty()) {
                rez.push_back(make_pair(getLValue(v[i]), getRValue(v, i)));
                if (v[i].find("</") == std::string::npos) {
                    while (v[i++].find("</") == std::string::npos);
                    i--;
                }
            }
        }
        return rez;
    }

}
