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

    std::string ParserFile::find(std::string &s, std::vector<std::string> v, unsigned int i)
    {
        std::string ec;
        if (i > v.size())
            return ec;

        while (i < v.size()) {
            if (v[i].find(s, 0) != std::string::npos)
                return v[i];
            i++;
        }
        return ec;
    }

    std::vector<std::string> ParserFile::findA(std::string &s, std::vector<std::string> v)
    {
        std::vector<std::string> r;

        for (unsigned int i = 0; i < v.size(); i++)
            if (v[i].find(s, 0) != std::string::npos)
                r.push_back(v[i]);
        return r;
    }

    std::vector<std::string> ParserFile::cleanContent(File &f) { return cleanVector(f.getContent()); }

    std::vector<std::string> ParserFile::cleanContent(std::vector<std::string> v) { return cleanVector(v); }

    std::string ParserFile::findStr(std::string s, File f, unsigned int i) { return find(s, f.getContent(), i); }

    std::string ParserFile::findStr(std::string s, std::vector<std::string> v, unsigned int i) { return find(s, v, i); }

    std::vector<std::string> ParserFile::findAStr(std::string s, File f) { return findA(s, f.getContent()); }

    std::vector<std::string> ParserFile::findAStr(std::string s, std::vector<std::string> v) { return findA(s, v); }

}
