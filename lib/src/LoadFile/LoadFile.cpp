/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

# include "LoadFile.hpp"

namespace fileManager {

    LoadFile::LoadFile(std::string &path)
    {
    }

    std::unique_ptr<IFile> LoadFile::getAllFile()
    {
    }

    std::unique_ptr<IFile> LoadFile::getFileByExtension(std::string extension, int position)
    {
    }

    std::vector<std::unique_ptr<IFile>> LoadFile::getAFileByExtension(std::string extension)
    {
    }

    std::unique_ptr<IFile> LoadFile::getFileByName(std::string name, int position)
    {
    }

    std::vector<std::unique_ptr<IFile>> LoadFile::getAFileByName(std::string name)
    {
    }

    std::unique_ptr<IFile> LoadFile::getFileByPath(std::string path)
    {
    }

    int LoadFile::getFileNumber()
    {
    }

    int LoadFile::getFileNumberWExtension(std::string extension)
    {
    }

    int LoadFile::getFileNumberWName(std::string name)
    {
    }

    std::unique_ptr<IFile> &LoadFile::operator[](int poisition)
    {
    }

    bool LoadFile::addFile()
    {
    }

    bool LoadFiledelFile()
    {
    }

    bool LoadFile::load(std::string path)
    {
    }

    bool LoadFile::load(std::vector<std::string> path)
    {
    }

}
