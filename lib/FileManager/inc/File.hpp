/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** File
*/

#pragma once

    #include <iostream>
    #include <vector>

namespace FileManager {

    class File final {

        public:

            File() = default;
            File(const std::string &path);

            /* Change path */
            bool setPath(const std::string &path);

            /* Getters */
            std::string &getExtension();
            std::string &getName();
            std::string &getPath();
            std::vector<std::string> getContent();

        private:

            /* Parsing */
            bool load();
            bool isFile();
            size_t getLength(std::string &s);
            void parseName(std::string s);
            void parseExt(std::string s);
            void cleanRessources();

        private:

            std::string _ext;
            std::string _name;
            std::string _path;

    };

}
