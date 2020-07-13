/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** JSONParser
*/

#pragma once

    #include <iostream>
    #include <vector>

    #include "File.hpp"

namespace FormatParser {

    class JSONParser final {

        public:

            JSONParser() = default;

            /* Parse */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f) const { return parseAD(f.getContent()); }
            inline std::vector<std::pair<std::string, std::string>> parse(const std::vector<std::string> &v) const { return parseAD(v); }

            /* Parse Section */
            inline std::vector<std::pair<std::string, std::string>> parse(FileManager::File &f, const std::string &match) const { return parseS(f.getContent(), match); }
            inline std::vector<std::pair<std::string, std::string>> parse(const std::vector<std::string> &v, const std::string &match) const { return parseS(v, match); }

            /* Parse RV */
            inline std::string parseRV(FileManager::File &f, const std::string &match) const { return parseO(f.getContent(), match); }
            inline std::string parseRV(const std::vector<std::string> &v, const std::string &match) const { return parseO(v, match); }

            /* Get Section Name(s) */
            inline std::vector<std::string> getSection(FileManager::File &f) const { return getSName(f.getContent()); }
            inline std::vector<std::string> getSection(const std::vector<std::string> &v) const { return getSName(v); }

        private:

            /* Parsing LV & RV */
            std::string getLValue(const std::string &s) const;
            std::string getRValue(const std::string &s) const;

            /* Compute LV & RV */
            size_t makePair(const std::vector<std::string> &v, std::vector<std::pair<std::string, std::string>> &r, size_t it) const;

            /* Parsing */
            std::vector<std::pair<std::string, std::string>> parseAD(const std::vector<std::string> &v) const;
            std::vector<std::pair<std::string, std::string>> parseS(const std::vector<std::string> &v, const std::string &match) const noexcept;
            std::string parseO(const std::vector<std::string> &v, const std::string &match) const noexcept;

            /* Parsing Section Name(s) */
            std::vector<std::string> getSName(const std::vector<std::string> &v) const;

    };

}
