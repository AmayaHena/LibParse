/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#pragma once

    #include <iostream>
    #include <vector>

namespace fileManager {

    class File final {

        public:

            File() = default;
            File(std::string &path);
            ~File() noexcept;

            /* Reload */
            bool refresh();
            bool setPath(std::string &path);

            /* Getters */
            std::string &getExtension();
            std::string &getName();
            std::string &getPath();
            std::vector<std::string> getContent();

        private:

            /* Parsing */
            void cleanRessources();
            bool loadFile();
            bool parseInfo();
            bool parsingFile();

        private:

            std::string _extension;
            std::string _name;
            std::string _path;
            std::vector<std::string> _content;

    };

}
