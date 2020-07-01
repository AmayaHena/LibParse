/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** Parser
*/

#pragma once

    #include "File.hpp"

namespace FileManager {

    class Parser final {

        public:

            Parser() = default;
            ~Parser() = default;

            /* Clean a content of a File object */
            std::vector<std::string> cleanContent(File &f);
            std::vector<std::string> cleanContent(std::vector<std::string> v);

            /* Scearch Tool */
            std::string findStr(std::string s, File &f, size_t i = 0);
            std::string findStr(std::string s, std::vector<std::string> v, size_t i = 0);

        private:

            /* Clean */
            std::string cleanLine(std::string s);
            std::vector<std::string> cleanVector(std::vector<std::string> v);

            /* Parse */
            std::string find(std::string &s, std::vector<std::string> v, size_t i);

    };

}
