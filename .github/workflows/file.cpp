/*
** EPITECH PROJECT, 2020
** LibParse
** File description:
** main
*/

#include <fstream>

#include <vector>
#include <iostream>

#include "../../lib/FileManager/inc/File.hpp"

std::vector<std::string> getFile(std::string s)
{
    std::vector<std::string> v;
    std::fstream f(s);
    if (!f)
        return v;

    std::string tmp;
    while(std::getline(f, tmp))
        v.push_back(tmp);
    f.close();
    return v;
}

int main()
{
    /* INIT */
    FileManager::File f("../../CMakeLists.txt");

    FileManager::File f1;
    FileManager::File f2;

    /* TESTTING LOAD EC */

    if (f1.setPath("cuties.txt"))
        return 84;
    if (f2.setPath("waifus/mostimo.OWO"))
        return 84;

    std::cout << "LOAD EC : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TESTTING LOAD */

    if (!f1.setPath("../../.gitignore"))
        return 84;
    if (!f2.setPath("../../lib/FileManager/inc/File.hpp"))
        return 84;

    std::cout << "LOAD : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    /* TESTTING EXT */

    if (f.getExtension() != "txt")
        return 84;
    if (f1.getExtension() != "gitignore")
        return 84;
    if (f2.getExtension() != "hpp")
        return 84;

    std::cout << "EXT : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    /* TESTTING PATH */

    if (f.getPath() != "../../CMakeLists.txt")
        return 84;
    if (f1.getPath() != "../../.gitignore")
        return 84;
    if (f2.getPath() != "../../lib/FileManager/inc/File.hpp")
        return 84;

    std::cout << "PATH : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    /* TESTTING NAME */

    if (f.getName() != "CMakeLists")
        return 84;
    if (f1.getName() != "")
        return 84;
    if (f2.getName() != "File")
        return 84;

    std::cout << "NAME : \t\t[\033[1;32mOK\033[0m]" << std::endl;

    /* TESTTING CONTENT */

    std::vector<std::string> vt = f.getContent();
    std::vector<std::string> vo = getFile(f.getPath());

    if (vt.size() != vo.size())
        return 84;
    for (size_t it = 0; it < vt.size(); it++)
        if (vt[it] != vo[it])
            return 84;
    vt.clear();
    vo.clear();

    vt = f1.getContent();
    vo = getFile(f1.getPath());
    if (vt.size() != vo.size())
        return 84;
    for (size_t it = 0; it < vt.size(); it++)
        if (vt[it] != vo[it])
            return 84;
    vt.clear();
    vo.clear();

    vt = f2.getContent();
    vo = getFile(f2.getPath());
    if (vt.size() != vo.size())
        return 84;
    for (size_t it = 0; it < vt.size(); it++)
        if (vt[it] != vo[it])
            return 84;
    vt.clear();
    vo.clear();

    std::cout << "CONTENT : \t[\033[1;32mOK\033[0m]" << std::endl;

    return 0;
}
