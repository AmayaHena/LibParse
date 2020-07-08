/*
** EPITECH PROJECT, 2020
** LibParse
** File description:
** main
*/

#include "../lib/FileManager/inc/File.hpp"

int main()
{
    /* TESTTING LOAD */
    FileManager::File f("../CMakeLists.txt");

    FileManager::File f1;
    FileManager::File f2;

    if (!f1.setPath("../.gitignore"))
        return 84;
    if (!f2.setPath("../lib/FileManager/inc/File.hpp"))
        return 84;

    std::cout << "LOAD : OK" << std::endl;

    if (f.getExtension() != "txt")
        return 84;
    if (f1.getExtension() != "gitignore")
        return 84;
    if (f2.getExtension() != "hpp")
        return 84;

    std::cout << "EXT : OK" << std::endl;

    if (f.getPath() != "../CMakeLists.txt")
        return 84;
    if (f1.getPath() != "../.gitignore")
        return 84;
    if (f2.getPath() != "../lib/FileManager/inc/File.hpp")
        return 84;

    std::cout << "PATH : OK" << std::endl;

    if (f.getName() != "CMakeLists")
        return 84;
    if (f1.getName() != "")
        return 84;
    if (f2.getName() != "File")
        return 84;

    std::cout << "NAME : OK" << std::endl;

    std::cout << "---" << std::endl;

    for (std::string s : f.getContent())
        std::cout << s << std::endl;

    std::cout << "---" << std::endl;

    for (std::string s : f1.getContent())
        std::cout << s << std::endl;

    std::cout << "---" << std::endl;

    for (std::string s : f2.getContent())
        std::cout << s << std::endl;

    return 0;
}

// g++ main.cpp -fPIC ../libNyx.so -I ../lib/inc/FileManager/
// LD_PRELOAD=../libNyx.so ./a.out
