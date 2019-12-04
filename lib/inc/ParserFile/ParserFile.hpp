/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ParserFILE
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

    # include "LoadFile.hpp"

namespace fileManager {

    class ParserFile {

        public:

            ParserFile() = default;
            ~ParserFile() = default;

            /* Clean a content of a File object */
            std::vector<std::string> cleanContent(File &f);
            std::vector<std::string> cleanContent(std::vector<std::string> v);

        private:

            /* Tools clean */
            std::string cleanLine(std::string s);
            std::vector<std::string> cleanVector(std::vector<std::string> v);

    };

}

#endif /* !PARSERFILE_HPP_ */
