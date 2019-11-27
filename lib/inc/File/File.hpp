/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#ifndef File_HPP_
#define File_HPP_

    # include "IFile.hpp"

namespace fileManager {

    class File : public IFile {

        public:

            File() = default;
            File(std::string path);

            /* Setter */
            bool setPath(std::string path);

            /* Getters */
            std::string getExtension() final;
            std::string getName() final;
            std::string getPath() final;
            std::vector<std::string> getContent() final;

        private:

            /* Parsing */
            void cleanRessources();
            bool loadFile();
            bool parseInfo();
            bool parsingFile();

            std::string _extension;
            std::string _name;
            std::string _path;
            std::vector<std::string> _content;

    };

}

#endif /* File_HPP_ */
