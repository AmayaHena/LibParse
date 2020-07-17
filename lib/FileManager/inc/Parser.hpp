/*
** PERSONAL PROJECT, 2020
** Nyx
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
            inline std::vector<std::string> trim(File &f) const { return trimCont(f.getContent()); }
            inline std::vector<std::string> trim(const std::vector<std::string> &v) const { return trimCont(v); }

            /* Parse */
            inline std::string find(const std::string &s, File &f, size_t i = 0) const { return findS(s, f.getContent(), i); }
            inline std::string find(const std::string &s, const std::vector<std::string> &v, size_t i = 0) const { return findS(s, v, i); }

            /* Parse Raw String */
            std::string getRawString(const std::string &s, char c = '\"', size_t i = 0) const;

        private:

            /* Cleaning */
            void trimLine(std::string &s) const;
            std::vector<std::string> trimCont(std::vector<std::string> v) const noexcept;

            /* Parsing */
            std::string findS(const std::string &s, const std::vector<std::string> &v, size_t i) const noexcept;

    };

}
