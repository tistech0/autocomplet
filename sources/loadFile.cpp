/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** loadFile
*/

#include "Gps.hpp"
#include "formatString.hpp"
#include "exceptions/InvalideArgument.hpp"
#include <fstream>
#include <regex>

static bool isGoodLine(std::string *line)
{
    std::regex adressPattern("(^[a-zA-Z ]+)[,]\\s*([0-9]+)\\s*(boulevard|allée|allee|rue|avenue|chemin|impasse|place|quai|square)\\s*[a-zA-Z 'Ü-ü-]+$");
	std::smatch sm;

    if (std::regex_match(*line, sm, adressPattern))
        return (true);
    formatString(line);
    if (!std::regex_match(*line, sm, adressPattern)){
        std::cerr << *line << std::endl;
        return (false);
    }
    return (true);
}

int loadFile(char *filepath, Gps *core)
{
    std::ifstream ifs(filepath);
    adressSpace::Adress *tmp;
    int i = 0;
    
    if (!ifs.is_open())
        throw InvalideArgumentError();
    
    for(std::string line; std::getline(ifs, line );) {
        if (isGoodLine(&line) == true) {
            tmp = new adressSpace::Adress(line);
            core->addAdress(*tmp);
            delete tmp;
            i++;
        }
    }
    if (i == 0)
        throw InvalideArgumentError();
    if (i == 1) {
        std::cout << "=> " << core->getDico().begin()->second[0].getAllAdress() << std::endl;
        return (1);
    }
    return (0);
}