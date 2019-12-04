/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ParserFile
*/

#include "ParserFile.hpp"

namespace fileManager {

    std::string ParserFile::cleanLine(std::string s)
    {
        for (int i = s.size(); i >= 0; i--) {
            if (s[i] == ' ') {
                s.erase(i);
                if (s[i - 1] != ' ')
                    break;
            }
        }
        return s;
    }

    std::vector<std::string> ParserFile::cleanVector(std::vector<std::string> v)
    {
        std::vector<std::string> r;
        std::string tmp;

        for (const std::string &s: v) {
            if (!v.empty())
                tmp = cleanLine(s);
            if (!s.empty()) {
                r.push_back(tmp);
                tmp.clear();
            }
        }

        return r;
    }

    std::vector<std::string> ParserFile::cleanContent(File &f) { return cleanVector(f.getContent()); }

    std::vector<std::string> ParserFile::cleanContent(std::vector<std::string> v) { return cleanVector(v); }

}
