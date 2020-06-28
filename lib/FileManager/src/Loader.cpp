/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** Loader
*/

#include "Loader.hpp"

namespace FileManager {

    /* CTOR & DTOR */

    Loader::Loader(std::string path) { load(path); }

    /* PUBLIC METHOD */

    bool Loader::load(std::string path)
    {
        for (File &f : _cont)
            if (f.getPath() == path)
                return false;

        if (!_f.setPath(path))
            return false;

        _cont.push_back(std::move(_f));
        return true;
    }

    void Loader::delFile(size_t position) { _cont.erase(_cont.begin() + position); }

    size_t Loader::getFileNb() { return _cont.size(); }

    File &Loader::operator[](size_t position) { return _cont.at(position); }

    /* PRIVATE METHOD */

}
