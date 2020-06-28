/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** Loader
*/

#pragma once

    #include "File.hpp"

namespace FileManager {

    class Loader final {

        public:

            Loader() = default;
            Loader(std::string path);

            /* Management of File(s) object(s) */
            bool load(std::string path);
            void delFile(size_t position);

            /* Getters */
            size_t getFileNb();

            /* Overloading Operator */
            File &operator[](size_t position);

        private:

            /* Container */
            std::vector<File> _cont;

            /* File object */
            File _f;

    };

}
