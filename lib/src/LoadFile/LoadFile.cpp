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

    std::vector<File> LoadFile::getAllFile()
    {
        return _container;
    }

    File &LoadFile::getFileByExtension(std::string extension, unsigned int position)
    {
        for (unsigned int i = position; i < _container.size(); i++)
            if (_container[i].getExtension() == extension)
                return _container.at(i);
        return _container.at(position);
    }

    std::vector<File> LoadFile::getAFileByExtension(std::string &extension)
    {
        std::vector<File> v;

        for (File &f : _container)
            if (f.getExtension() == extension)
                v.push_back(f);
        return v;
    }

    File &LoadFile::getFileByName(std::string name, unsigned int position)
    {
        for (unsigned int i = position; i < _container.size(); i++)
            if (_container[i].getName() == name)
                return _container.at(i);
        return _container.at(position);
    }

    std::vector<File> LoadFile::getAFileByName(std::string &name)
    {
        std::vector<File> v;
        unsigned int i = 0;

        for (File &f : _container) {
            if (f.getName() == name)
                v.push_back(_container.at(i));
            i++;
        }
        return v;
    }

    File &LoadFile::getFileByPath(std::string path)
    {
        for (File &f : _container)
            if (f.getPath() == path)
                return f;
        return _container.at(0);
    }

    int unsigned LoadFile::getFileNumber() { return _container.size(); }

    int unsigned LoadFile::getFileNumberWExtension(std::string extension)
    {
        unsigned int i = 0;

        for (File &f : _container)
            if (f.getExtension() == extension)
                i++;
        return i;
    }

    int unsigned LoadFile::getFileNumberWName(std::string name)
    {
        unsigned int i = 0;

        for (File &f : _container)
            if (f.getName() == name)
                i++;
        return i;
    }

    File &LoadFile::operator[](unsigned int position)
    {
        return _container.at(position);
    }

    bool LoadFile::addFile(std::string &path)
    {
        for (unsigned int i = 0; i < _container.size(); i++)
            if (_container[i].getPath() == path)
                delFile(i);

        File f;

        if (!f.setPath(path))
            return false;
        _container.push_back(std::move(f));
        return true;
    }

    void LoadFile::delFile(unsigned int position)
    {
        _container.erase(_container.begin() + position);
    }

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
