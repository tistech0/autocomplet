/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** coreLoop
*/

#include "Gps.hpp"
#include "exceptions/UnknownAddress.hpp"
#include <regex>

static bool isGoodLine(std::string lineGet, bool isNumInput)
{
    std::regex linePattern("[a-zA-Z]");
    std::regex lineNumPattern("([0-9]|(ABORT))");
	std::smatch sm;
    
    if (lineGet.size() > 1 || lineGet.size() <= 0)
        return (false);
    if (std::regex_match(lineGet, sm, linePattern) && !isNumInput)
        return (true);
    else if (std::regex_match(lineGet, sm, lineNumPattern) && isNumInput)
        return (true);
    else
        return (false);
}

static void displayResult(Gps core)
{
    if (core.getInput()[core.getInput().size() - 1] == '1')
        std::cout << "=> " << core.getGoodCity()[0].getAllAdress() << std::endl;
    else
        std::cout << "=> " << core.getGoodCity()[1].getAllAdress() << std::endl;
}

void coreLoop(Gps core)
{
    std::string lineGet = "";
    bool end = false;
    int flag = 0;
    
    propalBegin(&core);
    while (lineGet != "ABORT" && !end) {
        std::getline(std::cin, lineGet);
        if (lineGet != "ABORT" && isGoodLine(lineGet, core.getIsNumInput()) == false)
            throw UnknownAddressError();
        else if (lineGet != "ABORT") {
            core.addInput(lineGet);
            if (core.getIsNumInput()) {
                displayResult(core);
                end = true;
            }
            if (core.getIsGoodCityName() && !end &&!core.getIsNumInput()){
                findAdress(&core);
                end = displayPropalAdress(&core, flag);
            }
            if (!core.getIsGoodCityName() && !core.getIsNumInput()) {
                findCity(&core);
                end = displayPropalCityName(&core);
            }
            if (core.getIsGoodCityName() && flag == 0 && !end) {
                displayPropalAdress(&core, flag);
                flag++;
            }
        }
    }
}