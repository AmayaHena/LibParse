/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#ifndef File_HPP_
#define File_HPP_

    # include <iostream>
    # include <vector>

namespace fileManager {

    class File{

        public:

            File() = default;
            File(std::string &path);

            /* Method Tool */
            bool refresh();

            /* Setter */
            bool setPath(std::string &path);

            /* Getters */
            std::string getExtension();
            std::string getName();
            std::string getPath();
            std::vector<std::string> getContent();

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
