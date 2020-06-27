/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

#pragma once

    #include "File.hpp"

namespace fileManager {

    class LoadFile final {

        public:

            LoadFile() = default;
            LoadFile(std::string path);
            LoadFile(std::vector<std::string> path);
            ~LoadFile() noexcept = default;

            /* Management of File(s) object(s) */
            bool load(std::string path);
            bool load(std::vector<std::string> path);
            void delFile(size_t position);

            /* Getters File(s) object(s) */
            std::vector<File> getAllFile();
            File &getFileByExtension(std::string extension, size_t position = 0);
            std::vector<File> getAFileByExtension(std::string extension);
            File &getFileByName(std::string name, size_t position = 0);
            std::vector<File> getAFileByName(std::string name);
            File &getFileByPath(std::string path);

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
