/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

#pragma once

    #include "File.hpp"

namespace FileManager {

    class LoadFile final {

        public:

            LoadFile() = default;
            LoadFile(std::string path);

            /* Management of File(s) object(s) */
            bool load(std::string path);
            void delFile(size_t position);

            /* Getters File(s) object(s) Stat(s) */
            size_t getFileNumber();
            size_t getFileNumberWExtension(std::string extension);
            size_t getFileNumberWName(std::string name);

            /* Overloading Operator */
            File &operator[](size_t position);

        private:

            /* Tools add & del */
            bool addFile(std::string &path);

        private:

            std::vector<File> _container;
            File _error;

    };

}
