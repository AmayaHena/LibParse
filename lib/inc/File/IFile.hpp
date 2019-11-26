/*
** PERSONAL PROJECT, 2019
** LibParse
** File description:
** IFile
*/

#ifndef IFile_HPP_
#define IFile_HPP_

    # include <iostream>
    # include <vector>

namespace fileManager {

    ///@class IFile
    /// File as an object with all specifications

    class IFile {

        public:

            virtual ~IFile();

            ///Function called for IFile



            /* Getter(s) specifications */

            ///Get extension of the File object

            ///Getter for extension of the file loaded as File object
            ///@return The extension of the file
            virtual std::string     getExtension();


            ///Get name of the File object

            ///Getter for name of the file loaded as File object
            ///@return The name of the file
            virtual std::string     getName();


            ///Get path of the File object

            ///Getter for path of the file loaded as File object
            ///@return The path of the file
            virtual std::string     getPath();


            ///Get content of the File object

            ///Getter for content of the file loaded as File object
            ///@return The content of the file
            virtual std::vector<std::string>    getContent();

    };

}

#endif /* IFile_HPP_ */