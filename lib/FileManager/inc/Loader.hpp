/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** Loader
*/

#pragma once

    #include "File.hpp"

namespace FileManager {

    class Loader final {

        public:

            Loader() = default;
            Loader(const std::string &path);
            ~Loader() noexcept;

            /* File Del & Load */
            bool load(const std::string &path) noexcept;
            bool delFile(const std::string &path) noexcept;
            bool delFile(size_t pos = 0) noexcept;

            /* Getters */
            bool isFile(const std::string &s) const noexcept;
            inline size_t getFileNb() const noexcept { return _cont.size(); }

            /* Overloading Operator */
            inline File &operator[](size_t pos) { return _cont.at(pos); }

        private:

            /* Container */
            std::vector<File> _cont;

            /* File object */
            File _f;

    };

}
