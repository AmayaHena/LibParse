/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ILoadFile
*/

#ifndef ILoadFile_HPP_
#define ILoadFile_HPP_

    # include "IFile.hpp"

    # include <memory>

namespace fileManager {

    ///@class ILoadFile
    /// Container of File(s) object(s) and sarch engine to get files

    class ILoadFile {

        public:

            virtual ~ILoadFile() = default;

            ///Function called for ILoadFile



            /* Load File(s) */

            ///Load a file by the path

            ///Load only one file by the path
            ///@param path is The path to the file would be load as File object
            ///@return The status of the load, false if something failed, true if everythis is fine
            virtual bool    load(std::string path) = 0;


            ///Load files by the paths

            ///Load multiple files by the paths
            ///@param paths is all paths of files would be load as File object
            ///@return The status of the load, false if something failed, true if everythis is fine
            virtual bool    load(std::vector<std::string> path) = 0;



            /* Getter(s) File(s) */

            ///Get all File(s)

            ///Get all file(s) in the container
            ///@return all The File(s) object(s)
            virtual std::unique_ptr<IFile>    getAllFile() = 0;


            ///Get first File by extension from a position

            ///Get the first File object inside the container according with the extension given
            ///@param extension is The extension to look for inside the container
            ///@param position is The position that the search will begin
            ///@return The File object according to the @param extension and @param position given
            virtual std::unique_ptr<IFile>    getFileByExtension(std::string extension, int position) = 0;


            ///Get all Files by extension

            ///Get all File(s) object(s) inside the container according with the extension given
            ///@param extension is The extension to look for inside the container
            ///@return The File(s) object(s) according to the extension @param extension given
            virtual std::vector<std::unique_ptr<IFile>>    getAFileByExtension(std::string extension) = 0;


            ///Get first File by name from a position

            ///Get the first File object inside the container according with the name given
            ///@param name is The extension to look for inside the container
            ///@param position is The position that the search will begin
            ///@return The File object according to the @param name and @param position given
            virtual std::unique_ptr<IFile>    getFileByName(std::string name, int position) = 0;


            ///Get all Files by name

            ///Get all File(s) object(s) inside the container according with the name given
            ///@param name is The name to look for inside the container
            ///@return The File(s) object(s) according to the @param name given
            virtual std::vector<std::unique_ptr<IFile>>    getAFileByName(std::string name) = 0;


            ///Get File by path

            ///Get the first File object inside the container according with the path given
            ///@param path is The path to look for inside the container
            ///@return The File object according to the extension @param path given
            virtual std::unique_ptr<IFile>    getFileByPath(std::string path) = 0;



            /* Getter(s) specification(s) */

            ///Get number of File(s) object(s)

            ///Get the number of File(s) object(s) in the container
            ///@return The number of File(s) object(s)
            virtual int    getFileNumber() = 0;


            ///Get number of File(s) object(s) with an specific extension

            ///Get the number of File(s) object(s) with an specific extension in the container
            ///@param extension is The extension to look for inside the container
            ///@return The number of File(s) object(s) according to @param extension given
            virtual int    getFileNumberWExtension(std::string extension) = 0;


            ///Get number of File(s) object in the container by name

            ///Get the number of File(s) object(s) with an specific extension in the container
            ///@param name is The extension to look for inside the container
            ///@return The number of File(s) object(s) according to @param name given
            virtual int    getFileNumberWName(std::string name) = 0;



            /* Operator Overload */

            ///Operator Overlaod []

            ///Get a File object by his number in the vector container of File object
            ///@param position is The current position of the file in the container
            ///@return The File object according to the position @param position given
            virtual std::unique_ptr<IFile> &operator[](int poisition) = 0;

    };

}

#endif /* ILoadFile_HPP_ */
