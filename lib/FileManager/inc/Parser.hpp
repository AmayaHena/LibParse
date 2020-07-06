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

            /* Clean */
            inline std::vector<std::string> clean(File &f) { return cleanV(f.getContent()); }
            inline std::vector<std::string> clean(const std::vector<std::string> &v) { return cleanV(v); }

            /* Parse */
            inline std::string find(const std::string &s, File &f, size_t i = 0)  { return findS(s, f.getContent(), i); }
            inline std::string find(const std::string &s, const std::vector<std::string> &v, size_t i = 0) { return findS(s, v, i); }

        private:

            /* Cleaning */
            void cleanG(std::string &s);
            std::vector<std::string> cleanV(std::vector<std::string> v);

            /* Parsing */
            std::string findS(const std::string &s, const std::vector<std::string> &v, size_t i);

    };

}
