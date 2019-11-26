/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#include "File.hpp"

#include <fstream>

namespace fileManager {

    File::File(std::string path) : _path(path) { parsingFile(); }

    bool File::setPath(std::string path)
    {
        if (!_path.empty())
            return false;
        _path = path;
        return parsingFile();
    }

    std::string File::getExtension()
    {
        return _extension;
    }

    std::string File::getName()
    {
        return _name;
    }

    std::string File::getPath()
    {
        return _path;
    }

    std::vector<std::string> File::getContent()
    {
        return _content;
    }

    bool File::loadFile()
    {
        std::fstream f(_path);

        if (!f)
            return false;
        std::string tmp;

        while(std::getline(f, tmp))
            _content.push_back(tmp);
        f.close();
        return true;
    }

    bool File::parseInfo()
    {
    }

    bool File::parsingFile()
    {
        if (!parseInfo() || !loadFile())
            return false;
        return true;
    }

};
