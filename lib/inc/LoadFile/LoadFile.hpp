/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** LoadFile
*/

#ifndef LoadFile_HPP_
#define LoadFile_HPP_

    # include "ILoadFile.hpp"
    # include "File.hpp"

namespace fileManager {

    class LoadFile : public ILoadFile {

        public:

            LoadFile() = default;
            LoadFile(std::string &path);
            LoadFile(std::vector<std::string> path);

            /* Load file(s) */
            bool load(std::string &path) final;
            bool load(std::vector<std::string> path) final;

            /* Getters File(s) object(s) */
            std::vector<std::unique_ptr<IFile>> getAllFile() final;
            std::unique_ptr<IFile> getFileByExtension(std::string &extension, int position) final;
            std::vector<std::unique_ptr<IFile>> getAFileByExtension(std::string &extension) final;
            std::unique_ptr<IFile> getFileByName(std::string &name, int position) final;
            std::vector<std::unique_ptr<IFile>> getAFileByName(std::string &name) final;
            std::unique_ptr<IFile> getFileByPath(std::string &path) final;

            /* Getters File(s) object(s) Stat(s) */
            int unsigned getFileNumber() final;
            int unsigned getFileNumberWExtension(std::string &extension) final;
            int unsigned getFileNumberWName(std::string &name) final;

            /* Overloading Operator */
            std::unique_ptr<IFile> &operator[](unsigned int poisition) final;

        private:

            /* Tools add & del */
            bool addFile(std::string &path);
            void delFile(unsigned int position);

            std::vector<std::unique_ptr<IFile>> _container;

    };

}

#endif /* LoadFile_HPP_ */
