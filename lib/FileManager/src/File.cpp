/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#include "File.hpp"

#include <fstream>
#include <bits/stdc++.h>

namespace FileManager {

    /* PUBLIC METHODS */

    File::File(const std::string &path) : _path(path) { load(); }

    bool File::setPath(const std::string &path)
    {
        if (path.empty())
            return false;
        cleanRessources();
        _path = path;
        return load();
    }

    std::string &File::getExtension() { return _ext; }

    std::string &File::getName() { return _name; }

    std::string &File::getPath() { return _path; }

    std::vector<std::string> File::getContent()
    {
        std::vector<std::string> cont;
        std::fstream f(_path);
        if (!f)
            return cont;

        std::string tmp;
        while(std::getline(f, tmp))
            cont.push_back(tmp);
        f.close();
        return cont;
    }

    /* PRIVATE METHODS */

    bool File::load()
    {
        if (!isFile())
            return false;
        parseExt(_path);
        _name = parseName(_path);
        return true;
    }

    bool File::isFile()
    {
        std::fstream f(_path);
        if (!f)
            return false;
        return true;
    }

    size_t File::getLength(std::string &s)
    {
        size_t p = s.find_last_of("/") + 1;

        for (size_t n = p; s[p]; n++)
            if (s[n] == '.')
                return n - p;
        return p;
    }

    std::string File::parseName(std::string s)
    {
        if (s.find(".") == std::string::npos
        && s.find("/") == std::string::npos)
            return s;

        if (s.find(".") != std::string::npos) {
            if (s.find("/") == std::string::npos)
                return s.substr(0, s.find_last_of("."));
            else
                return s.substr(s.find_last_of("/") + 1, getLength(s));
        }
        return s.substr(s.find_last_of("/") + 1, s.size());
    }

    void File::parseExt(std::string s)
    {
        if (s.find(".") == std::string::npos)
            _ext.clear();

        std::reverse(s.begin(), s.end());

        s = s.substr(0, s.find_first_of("."));
        std::reverse(s.begin(), s.end());
        _ext = s;
    }

    void File::cleanRessources()
    {
        _path.clear();
        _name.clear();
        _ext.clear();
    }

}