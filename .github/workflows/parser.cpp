/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** parser
*/

#include <fstream>

#include <vector>
#include <iostream>

#include "../../lib/FileManager/inc/Parser.hpp"

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
    FileManager::Parser p;
    FileManager::File f("../../CMakeLists.txt");

    /* TEST PARSE EC */
    if (p.find("NYA", f) != "")
        return 84;
    if (p.find("WAIFUS", f) != "")
        return 84;
    if (p.find("CUTIES", f) != "")
        return 84;

    std::cout << "PARSE EC : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST PARSE */
    if (p.find("SHARED", f) != "add_library(Nyx SHARED")
        return 84;
    if (p.find("CXX_FLAGS", f) != "SET(CMAKE_CXX_FLAGS \"-Wall -Wextra -pedantic -Werror\")")
        return 84;
    if (p.find("PUBLIC", f) != "    PUBLIC lib/FileManager/inc/")
        return 84;
    if (p.find("PUBLIC", f, 19) != "    PUBLIC lib/FormatParser/inc/")
        return 84;

    std::cout << "PARSE : \t[\033[1;32mOK\033[0m]" << std::endl;

    return 0;
}
