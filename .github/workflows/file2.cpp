/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** file
*/

#include <fstream>

#include <vector>
#include <iostream>

#include "../../lib/FileManager/inc/File.hpp"

int main()
{
    /* INIT */
    FileManager::File f("CMakeLists.txt");
    FileManager::File f2("build.sh");

    /* TEST CR & RM EC */
    if (!f.isFile())
        return 84;

    if (f.setPath("foo.txt"))
        return 84;

    if (!f.create())
        return 84;

    std::cout << "CR & RM EC : \t[\033[1;32mOK\033[0m]" << std::endl;

    /* TEST CR & RM */

    if (!f.write(f2.getContent()))
        return 84;

    if (!f.rm())
        return 84;

    if (!f.create(f2.getContent()))
        return 84;

    for (std::string s : f.getContent())
        std::cout << s << std::endl;

    if (!f.rm())
        return 84;

    if (f.isFile())
        return 84;

    std::cout << "CR & RM : \t[\033[1;32mOK\033[0m]" << std::endl;

    return 0;
}
