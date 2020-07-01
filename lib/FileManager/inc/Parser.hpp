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
            std::vector<std::string> clean(File &f);
            std::vector<std::string> clean(std::vector<std::string> &v);

            /* Scearch Tool */
            std::string find(std::string s, File &f, size_t i = 0);
            std::string find(std::string s, std::vector<std::string> v, size_t i = 0);

        private:

            /* Clean */
            void cleanL(std::string &s);
            std::vector<std::string> cleanV(std::vector<std::string> v);

            /* Parse */
            std::string findS(std::string &s, std::vector<std::string> v, size_t i);

    };

}
