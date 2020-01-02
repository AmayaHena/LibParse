/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#include "File.hpp"

#include <fstream>

namespace fileManager {

    File::File(std::string &path) : _path(path) { parsingFile(); }

    bool File::refresh()
    {
        if (_path.empty())
            return false;
        return loadFile();
    }

    bool File::setPath(std::string &path)
    {
        if (path.empty())
            return false;
        cleanRessources();
        _path = path;
        return parsingFile();
    }

    std::string &File::getExtension() { return _extension; }

    std::string &File::getName() { return _name; }

    std::string &File::getPath() { return _path; }

    std::vector<std::string> File::getContent() { return _content; }

    void File::cleanRessources()
    {
        _path.clear();
        _name.clear();
        _extension.clear();
        _content.clear();
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
        std::size_t point = _path.find(".");
        std::size_t slash = _path.find("/");

        if (slash == std::string::npos
        && point == std::string::npos) {
            _name = _path;
            _extension.clear();
            return true;
        }

        if (point != std::string::npos)
            _extension = _path.substr(point, _path.length());
        else
            _extension = nullptr;

        if (point != std::string::npos
        && slash == std::string::npos) {
            _name = _path.substr(0, point);
            return true;
        }

        for (slash = _path.length(); _path[slash] != '/'; slash--);
        for (point = _path.length(); _path[point] != '.'; point--);
        _name = _path.substr(slash + 1, point - slash - 1);
        _extension = _path.substr(point, _path.length());
        if (_extension[1] == '/')
            _extension.clear();
        return true;
    }

    bool File::parsingFile()
    {
        if (!loadFile())
            return false;
        parseInfo();
        return true;
    }

}
