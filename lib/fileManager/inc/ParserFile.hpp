/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ParserFILE
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

    #include "LoadFile.hpp"

namespace fileManager {

    class ParserFile {

        public:

            ParserFile() = default;
            ~ParserFile() = default;

            /* Clean a content of a File object */
            std::vector<std::string> cleanContent(File &f);
            std::vector<std::string> cleanContent(std::vector<std::string> v);

            /* Scearch Tool */
            std::string findStr(std::string s, File &f, size_t i = 0);
            std::string findStr(std::string s, std::vector<std::string> v, size_t i = 0);
            std::vector<std::string> findAStr(std::string s, File &f);
            std::vector<std::string> findAStr(std::string s, std::vector<std::string> v);

        private:

            /* Tools clean */
            std::string cleanLine(std::string s);
            std::vector<std::string> cleanVector(std::vector<std::string> v);
            std::string find(std::string &s, std::vector<std::string> v, size_t i);
            std::vector<std::string> findA(std::string &s, std::vector<std::string> v);

    };

}

#endif /* !PARSERFILE_HPP_ */
