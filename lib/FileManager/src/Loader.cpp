/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** Loader
*/

#include "Loader.hpp"

namespace FileManager {

    /* CTOR & DTOR */

    Loader::Loader(const std::string &path) { load(path); }

    Loader::~Loader() { _cont.clear(); }

    /* PUBLIC METHOD */

    bool Loader::load(const std::string &path) noexcept
    {
        for (File &f : _cont)
            if (f.getPath() == path)
                return false;

        _cont.push_back({ path });
        return true;
    }

    bool Loader::delFile(const std::string &path) noexcept
    {
        for (size_t it = 0; it < _cont.size(); it++)
            if (_cont[it].getPath() == path)
                return delFile(it);
        return false;
    }

    bool Loader::delFile(size_t pos) noexcept
    {
        if (static_cast<int>(pos) < 0
        || pos > _cont.size()
        || _cont.size() == 0)
            return false;

        _cont.erase(_cont.begin() + pos);
        return true;
    }

    bool Loader::isFile(const std::string &s) const noexcept
    {
        for (const File &f : _cont)
            if (f.getPath() == s)
                return true;
        return false;
    }

}
