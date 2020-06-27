/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#include "File.hpp"

#include <fstream>
#include <bits/stdc++.h>

namespace fileManager {

    /* PUBLIC METHODS */

    File::File(std::string &path) : _path(path) { load(); }

    bool File::refresh() { return isFile(); } // to del

    bool File::setPath(std::string &path)
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
        return true;
    }

    bool File::isFile()
    {
        std::fstream f(_path);
        if (!f)
            return false;
        return true;
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
