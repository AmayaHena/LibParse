/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** Loader
*/

#include "Loader.hpp"

namespace FileManager {

    /* CTOR & DTOR */

    Loader::Loader(const std::string &path) { load(path); }

    Loader::~Loader() { _cont.clear(); }

    /* PUBLIC METHOD */

    bool Loader::load(const std::string &path)
    {
        for (File &f : _cont)
            if (f.getPath() == path)
                return false;

        if (!_f.setPath(path))
            return false;

        _cont.push_back(std::move(_f));
        return true;
    }

    bool Loader::delFile(const std::string &s)
    {
        for (size_t it = 0; it < _cont.size(); it++)
            if (_cont[it].getPath() == s)
                return delFile(it);
        return false;
    }

    bool Loader::delFile(size_t pos)
    {
        if (pos > _cont.size())
            return false;

        _cont.erase(_cont.begin() + pos);
        return true;
    }

    size_t Loader::getFileNb() { return _cont.size(); }

    bool Loader::isFile(const std::string &s)
    {
        for (const File &f : _cont)
            if (f.getPath() == s)
                return true;
        return false;
    }

}
