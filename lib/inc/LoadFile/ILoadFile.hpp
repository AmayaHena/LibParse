/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** ILoadFile
*/

#ifndef ILoadFile_HPP_
#define ILoadFile_HPP_

    # include <IFile.hpp>

///@class ILoadFile
/// Container of File(s) object(s) and sarch engine to get files

namespace fileManager {

    class ILoadFile {

        public:

            virtual ~ILoadFile();

            ///Function called for ILoadFile



            /* Load File(s) */

            ///Load a file by the path

            ///Load only one file by the path
            ///@param path is The path to the file would be load as File object
            ///@return The status of the load, false if something failed, true if everythis is fine
            virtual bool    load(std::string path);


            ///Load files by the paths

            ///Load multiple files by the paths
            ///@param paths is all paths of files would be load as File object
            ///@return The status of the load, false if something failed, true if everythis is fine
            virtual bool    load(std::vector<std::string> path);



            /* Getter(s) File(s) */

            ///Get a File object by position

            ///Get a File object by is number in the vector container of File object
            ///@param nb is The current position of the file in the container
            ///@return The File object according to the position @param nb given
            virtual IFile    getFilePosition(int position);


            ///Get first File by extension

            ///Get the first File object inside the container according with the extension given
            ///@param extension is The extension to look for inside the container
            ///@return The File object according to the extension @param extension given
            virtual IFile    getFileByExtension(std::string extension);


            ///Get all Files by extension

            ///Get all File(s) object(s) inside the container according with the extension given
            ///@param extension is The extension to look for inside the container
            ///@return The File(s) object(s) according to the extension @param extension given
            virtual std::vector<IFile>    getAFileByExtension(std::string extension);


            ///Get first File by name

            ///Get the first File object inside the container according with the extension given
            ///@param name is The extension to look for inside the container
            ///@return The File object according to the extension @param name given
            virtual IFile    getFileByName(std::string name);


            ///Get all Files by name

            ///Get all File(s) object(s) inside the container according with the extension given
            ///@param name is The extension to look for inside the container
            ///@return The File(s) object(s) according to the extension @param name given
            virtual std::vector<IFile>    getAFileByName(std::string name);


            ///Get File by path

            ///Get the first File object inside the container according with the extension given
            ///@param name is The extension to look for inside the container
            ///@return The File object according to the extension @param name given
            virtual IFile    getFileByName(std::string path);



            /* Getter(s) specification(s) */

            ///Get number of File(s) object(s)

            ///Get the number of File(s) object(s) in the container
            ///@return The number of File(s) object(s)
            virtual int    getFileNumber();


            ///Get number of File(s) object(s) with an specific extension

            ///Get the number of File(s) object(s) with an specific extension in the container
            ///@param extension is The extension to look for inside the container
            ///@return The number of File(s) object(s) according to @param extension given
            virtual int    getFileNumberWExtension(std::string extension);


            ///Get number of File(s) object in the container by name

            ///Get the number of File(s) object(s) with an specific extension in the container
            ///@param name is The extension to look for inside the container
            ///@return The number of File(s) object(s) according to @param name given
            virtual int    getFileNumberWName(std::string name);

    };

};

#endif /* ILoadFile_HPP_ */
