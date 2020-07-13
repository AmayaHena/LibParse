/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** loader
*/

#include "Loader.hpp"

int main()
{
    FileManager::Loader f;

    /* TEST DEL EC */
    if (f.delFile(0))
        return 84;
    if (f.delFile(15))
        return 84;
    if (f.delFile("kappa.txt"))
        return 84;

    std::cout << "DEL EC : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST LOAD EC */
    if (f.load("../ec.txt"))
        return 84;
    if (f.getFileNb() != 0)
        return 84;

    std::cout << "LOAD EC : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST LAOD */
    if (!f.load("../CMakeLists.txt"))
        return 84;
    if (f.getFileNb() != 1)
        return 84;
    if (!f.load("../.gitignore"))
        return 84;
    if (f.getFileNb() != 2)
        return 84;
    if (!f.load("../lib/FileManager/inc/File.hpp"))
        return 84;
    if (f.getFileNb() != 3)
        return 84;

    std::cout << "LOAD : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST ISFILE */

    if (f.isFile("../ec.txt"))
        return 84;
    if (!f.isFile("../CMakeLists.txt"))
        return 84;
    if (!f.isFile("../.gitignore"))
        return 84;
    if (!f.isFile("../lib/FileManager/inc/File.hpp"))
        return 84;

    std::cout << "ISFILE : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST DEL */

    if (f.delFile(89))
        return 84;
    if (f.delFile("ec.txt"))
        return 84;
    if (f.getFileNb() != 3)
        return 84;
    if (!f.delFile())
        return 84;
    if (f.getFileNb() != 2)
        return 84;
    if (!f.delFile("../.gitignore"))
        return 84;
    if (f.getFileNb() != 1)
        return 84;

    if (f.isFile("../CMakeLists.txt"))
        return 84;
    if (f.isFile("../.gitignore"))
        return 84;
    if (!f.isFile("../lib/FileManager/inc/File.hpp"))
        return 84;

    std::cout << "DEL : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    return 0;
}