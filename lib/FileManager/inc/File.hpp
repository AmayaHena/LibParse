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
            inline const std::string &getExtension() const { return _ext; };
            inline const std::string &getName() const { return _name; };
            inline const std::string &getPath() const { return _path; };
            std::vector<std::string> getContent();

        private:

            /* Parsing */
            bool load();

            size_t getLength(std::string &s);
            std::string parseName(std::string s);
            void parseExt(std::string s);

            void cleanRessources();

        private:

            std::string _ext;
            std::string _name;
            std::string _path;

    };

}
