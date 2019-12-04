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
        for (int i = s.size(); i >= 0; i--)
            if (s[i] == ' ')
                s.erase(i);
        return s;
    }

    std::vector<std::string> ParserFile::cleanVector(std::vector<std::string> v)
    {
        std::vector<std::string> r;

        for (const std::string &s: v) {
            if (!v.empty())
                r.push_back(s);
            else
                r.push_back(cleanLine(s));
        }
        return r;
    }

    std::vector<std::string> ParserFile::cleanContent(File &f) { return cleanVector(f.getContent()); }

    std::vector<std::string> ParserFile::cleanContent(std::vector<std::string> v) { return cleanVector(v); }

}
