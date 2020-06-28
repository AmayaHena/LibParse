/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ParserFile
*/

#include "ParserFile.hpp"

namespace FileManager {

    /* PUBLIC METHOD */

    std::vector<std::string> ParserFile::cleanContent(File &f) { return cleanVector(f.getContent()); }

    std::vector<std::string> ParserFile::cleanContent(std::vector<std::string> v) { return cleanVector(v); }

    std::string ParserFile::findStr(std::string s, File &f, size_t i) { return find(s, f.getContent(), i); }

    std::string ParserFile::findStr(std::string s, std::vector<std::string> v, size_t i) { return find(s, v, i); }

    std::vector<std::string> ParserFile::findAStr(std::string s, File &f) { return findA(s, f.getContent()); }

    std::vector<std::string> ParserFile::findAStr(std::string s, std::vector<std::string> v) { return findA(s, v); }

    std::vector<std::string> ParserFile::findAStr(std::string s, std::vector<File> v)
    {
        std::vector<std::string> r;

        for (File f: v)
            for (const std::string &s_tmp: findA(s, f.getContent()))
                r.push_back(s_tmp);

        return r;
    }

    /* PRIVATE METHOD */

    std::string ParserFile::cleanLine(std::string s)
    {
        if (s[s.size() - 1] != ' ')
            return s;

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
            if (!s.empty())
                tmp = cleanLine(s);
            if (!s.empty()) {
                r.push_back(tmp);
                tmp.clear();
            }
        }
        return r;
    }

    std::string ParserFile::find(std::string &s, std::vector<std::string> v, size_t i)
    {
        std::string ec;

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

        for (size_t i = 0; i < v.size(); i++)
            if (v[i].find(s, 0) != std::string::npos)
                r.push_back(v[i]);
        return r;
    }

}