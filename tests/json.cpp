/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** json
*/

#include "../lib/FormatParser/inc/JSONParser.hpp"

int main()
{
    FileManager::File f_tp("files/JSON/t1.json");
    FileManager::File f_p("files/JSON/t1_parsed.txt");

    if (!f_tp.isFile()
    || !f_p.isFile())
        return 84;

    FormatParser::JSONParser j;

    size_t it = 0;
    std::vector<std::string> v = f_p.getContent();

    for (std::pair<std::string, std::string> p : j.parse(f_tp)) {
        if (v[it] != (p.first + " " + p.second))
            return 84;
        it++;
    }

    return 0;
}
