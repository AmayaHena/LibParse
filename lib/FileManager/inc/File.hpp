/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** File
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include <unistd.h>
    #include <bits/stdc++.h>

namespace FileManager {

    class File final {

        public:

            File() = default;
            File(const File &f);
            File(const std::string &path);
            ~File() noexcept;

            /* Change path */
            bool setPath(const std::string &path);

            /* Management */
            inline bool isFile() { return access(_path.c_str(), F_OK ) != -1; }
            bool rm();
            inline bool create() { return createFile(); }
            bool create(const std::vector<std::string> &in);

            /* Getters */
            inline const std::string &getExtension() const { return _ext; }
            inline const std::string &getName() const { return _name; }
            inline const std::string &getPath() const { return _path; }
            std::vector<std::string> getContent();

        private:

            /* Create */
            bool createFile();

            /* Parsing */
            bool load();
            size_t getLength(std::string &s);
            std::string parseName(std::string s);
            void parseExt(std::string s);

        private:

            std::string _ext;
            std::string _name;
            std::string _path;

    };

}
