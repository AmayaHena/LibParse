/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

# include "LoadFile.hpp"

namespace fileManager {

//    LoadFile::LoadFile(std::string &path) { load(path); }

//    LoadFile::LoadFile(std::vector<std::string> path) { load(path); }

/*     std::vector<std::unique_ptr<IFile>> LoadFile::getAllFile()
    {
        return _container;
    } */    // HERE

    /* std::unique_ptr<IFile> LoadFile::getFileByExtension(std::string &extension, int position)
    {
        for (unsigned int i = position; i < _container.size(); i++)
            if (_container[i]->getExtension() == extension)
                return _container[i];
        return std::unique_ptr(nullptr);
    } */

/*     std::vector<std::unique_ptr<IFile>> LoadFile::getAFileByExtension(std::string &extension)
    {
        std::vector<std::unique_ptr<IFile>> v;

        for (const std::unique_ptr<IFile> &f : _container)
            if (f->getExtension() == extension)
                v.push_back(f);
        return v;
    } */

    /* std::unique_ptr<IFile> LoadFile::getFileByName(std::string &name, int position)
    {
        for (unsigned int i = position; i < _container.size(); i++)
            if (_container[i]->getName() == name)
                return _container[i];
        return std::unique_ptr(nullptr);
    } */

/*     std::vector<std::unique_ptr<IFile>> LoadFile::getAFileByName(std::string &name)
    {
        std::vector<std::unique_ptr<IFile>> v;

        for (const std::unique_ptr<IFile> &f : _container)
            if (f->getName() == name)
                v.push_back(f);
        return v;
    } */

    /* std::unique_ptr<IFile> LoadFile::getFileByPath(std::string &path)
    {
        for (const std::unique_ptr<IFile> &f : _container) {
            if (f->getPath() == path)
                return f;
        }
        return std::unique_ptr(nullptr);
    } */

    int unsigned LoadFile::getFileNumber() { return _container.size(); }

    int unsigned LoadFile::getFileNumberWExtension(std::string &extension)
    {
        unsigned int i = 0;

        for (const std::unique_ptr<IFile> &f : _container)
            if (f->getExtension() == extension)
                i++;
        return i;
    }

    int unsigned LoadFile::getFileNumberWName(std::string &name)
    {
        unsigned int i = 0;

        for (const std::unique_ptr<IFile> &f : _container)
            if (f->getName() == name)
                i++;
        return i;
    }

    std::unique_ptr<IFile> &LoadFile::operator[](unsigned int position) { return _container[position]; }

    bool LoadFile::addFile(std::string &path)
    {
        for (unsigned int i = 0; i < _container.size(); i++)
            if (_container[i]->getPath() == path)
                delFile(i);

        std::unique_ptr<IFile> f = std::make_unique<File>();

        if (!f->setPath(path))
            return false;
        _container.push_back(std::move(f));
        return true;
    }

    void LoadFile::delFile(unsigned int position)
    {
        _container.erase(_container.begin() + position);
    }

    bool LoadFile::load(std::string &path)
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
