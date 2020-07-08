/*
** EPITECH PROJECT, 2020
** LibParse
** File description:
** main
*/

#include "../../lib/FileManager/inc/File.hpp"

int main()
{
    /* TESTTING LOAD */
    FileManager::File f("../../CMakeLists.txt");

    FileManager::File f1;
    FileManager::File f2;

    if (!f1.setPath("../../.gitignore"))
        return 84;
    if (!f2.setPath("../../lib/FileManager/inc/File.hpp"))
        return 84;

    std::cout << "LOAD : OK" << std::endl;

    if (f.getExtension() != "txt")
        return 84;
    if (f1.getExtension() != "gitignore")
        return 84;
    if (f2.getExtension() != "hpp")
        return 84;

    std::cout << "EXT : OK" << std::endl;

    if (f.getPath() != "../../CMakeLists.txt")
        return 84;
    if (f1.getPath() != "../../.gitignore")
        return 84;
    if (f2.getPath() != "../../lib/FileManager/inc/File.hpp")
        return 84;

    std::cout << "PATH : OK" << std::endl;

    if (f.getName() != "CMakeLists")
        return 84;
    if (f1.getName() != "")
        return 84;
    if (f2.getName() != "File")
        return 84;

    std::cout << "NAME : OK" << std::endl;

    return 0;
}
