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
        if (!addFile(path))
            return false;
        return true;
    }

    void Loader::delFile(size_t position) { _container.erase(_container.begin() + position); }

    size_t Loader::getFileNumber() { return _container.size(); }

    size_t Loader::getFileNumberWExtension(std::string extension)
    {
        size_t i = 0;

        for (File &f : _container)
            if (f.getExtension() == extension)
                i++;
        return i;
    }

    size_t Loader::getFileNumberWName(std::string name)
    {
        size_t i = 0;

        for (File &f : _container)
            if (f.getName() == name)
                i++;
        return i;
    }

    File &Loader::operator[](size_t position) { return _container.at(position); }

    /* PRIVATE METHOD */

    bool Loader::addFile(std::string &path)
    {
        /* for (size_t i = 0; i < _container.size(); i++)
            if (_container[i].getPath() == path)
                return _container[i].refresh(); */

        File f;
        if (!f.setPath(path))
            return false;
        _container.push_back(std::move(f));
        return true;
    }

}
