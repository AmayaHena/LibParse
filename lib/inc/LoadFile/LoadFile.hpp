/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

#ifndef LoadFile_HPP_
#define LoadFile_HPP_

    # include "File.hpp"

namespace fileManager {

    class LoadFile {

        public:

            LoadFile() = default;
            LoadFile(std::string path);
            LoadFile(std::vector<std::string> path);

            /* Management of File(s) object(s) */
            bool load(std::string path);
            bool load(std::vector<std::string> path);
            void delFile(unsigned int position);

            /* Getters File(s) object(s) */
            std::vector<File> getAllFile();
            File &getFileByExtension(std::string extension, unsigned int position);
            std::vector<File> getAFileByExtension(std::string &extension);
            File &getFileByName(std::string name, unsigned int position);
            std::vector<File> getAFileByName(std::string &name);
            File &getFileByPath(std::string path);

            /* Getters File(s) object(s) Stat(s) */
            int unsigned getFileNumber();
            int unsigned getFileNumberWExtension(std::string extension);
            int unsigned getFileNumberWName(std::string name);

            /* Overloading Operator */
            File &operator[](unsigned int poisition);

        private:

            /* Tools add & del */
            bool addFile(std::string &path);

            std::vector<File> _container;
            File _error;

    };

}

#endif /* LoadFile_HPP_ */
