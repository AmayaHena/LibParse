/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

# include "LoadFile.hpp"

namespace fileManager {

    LoadFile::LoadFile(std::string path) { load(path); }

    LoadFile::LoadFile(std::vector<std::string> path) { load(path); }

    std::vector<File> LoadFile::getAllFile() { return _container; }

    File &LoadFile::getFileByExtension(std::string extension, size_t position)
    {
        for (size_t i = position; i < _container.size(); i++)
            if (_container[i].getExtension() == extension)
                return _container.at(i);
        return _error;
    }

    std::vector<File> LoadFile::getAFileByExtension(std::string extension)
    {
        std::vector<File> v;

        for (File &f : _container)
            if (f.getExtension() == extension)
                v.push_back(f);
        return v;
    }

    File &LoadFile::getFileByName(std::string name, size_t position)
    {
        for (size_t i = position; i < _container.size(); i++)
            if (_container[i].getName() == name)
                return _container.at(i);
        return _error;
    }

    std::vector<File> LoadFile::getAFileByName(std::string name)
    {
        std::vector<File> v;

        for (File &f : _container)
            if (f.getName() == name)
                v.push_back(f);
        return v;
    }

    File &LoadFile::getFileByPath(std::string path)
    {
        for (File &f : _container)
            if (f.getPath() == path)
                return f;
        return _error;
    }

    size_t LoadFile::getFileNumber() { return _container.size(); }

    size_t LoadFile::getFileNumberWExtension(std::string extension)
    {
        size_t i = 0;

        for (File &f : _container)
            if (f.getExtension() == extension)
                i++;
        return i;
    }

    size_t LoadFile::getFileNumberWName(std::string name)
    {
        size_t i = 0;

        for (File &f : _container)
            if (f.getName() == name)
                i++;
        return i;
    }

    File &LoadFile::operator[](size_t position) { return _container.at(position); }

    bool LoadFile::addFile(std::string &path)
    {
        for (size_t i = 0; i < _container.size(); i++)
            if (_container[i].getPath() == path)
                return _container[i].refresh();

        File f;
        if (!f.setPath(path))
            return false;
        _container.push_back(std::move(f));
        return true;
    }

    void LoadFile::delFile(size_t position) { _container.erase(_container.begin() + position); }

    bool LoadFile::load(std::string path)
    {
        if (!addFile(path))
            return false;
        return true;
    }

    bool LoadFile::load(std::vector<std::string> path)
    {
        for (std::string &s : path)
            if (!addFile(s))
                return false;
        return true;
    }

}
