/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** firstPropal
*/

#include "Gps.hpp"

static void displayFirstLetter(std::map<std::string, int> allOcur)
{
    std::map<std::string, int> mapTemp = allOcur;
    std::map<std::string, int>::iterator actualUt;
    int actualOcur;
    std::string actualChar;
    size_t i = 0;
    size_t sizeMax = mapTemp.size() - 1;

    while (mapTemp.size() > 0 && i < 5) {
        actualOcur = 0;
        for (std::map<std::string, int>::iterator ut = mapTemp.begin(); ut != mapTemp.end(); ut++) {
            if (actualOcur < ut->second) {
                actualChar = ut->first;
                actualOcur = ut->second;
                actualUt = ut;
            }
        }
        std::cout << "{" << actualChar << "}";
        mapTemp.erase(actualUt);
        if (sizeMax > i)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
}

void propalBegin(Gps *core)
{
    std::map<std::string, int> allOcur;
    std::map<std::string, std::vector<adressSpace::Adress>> mapTemp = core->getDico();
    std::map<std::string, std::vector<adressSpace::Adress>>::iterator it = mapTemp.begin();
    std::vector<adressSpace::Adress> vectorTemp;
    std::vector<adressSpace::Adress>::iterator vectorItTemp;
    std::string cityRef = it->second[0].getCityName();;
    std::string letter;
    std::string tmp;
    std::string equal = "";
    size_t nbEqual = 0;
    int index = 0;

    if (core->getDico().size() == 1 && it->second.size() > 1) {
        core->setIsGoodCityName(true);
        for (size_t i = 0; i < it->second.size(); i++) {
                it->second[i].setCityName(toUpperCase(it->second[i].getCityName()));
                core->addGoodCity(it->second[i]);
        }
        core->setInput(it->second[0].getCityName());
        displayPropalAdress(core, 1);
        return;
    }

    for (unsigned int i = 0; i < cityRef.size() - 1; i++) {
        for (; it != mapTemp.end(); it++) {
            if (cityRef[i] == it->second[0].getCityName()[i]) {
                nbEqual++;
            }
        }
        if (nbEqual == mapTemp.size()) {
            equal += std::toupper(cityRef[i]);
            nbEqual = 0;
        } else 
            break;
    }
    it = mapTemp.begin();
    for (; it != mapTemp.end(); it++) {
        vectorTemp = it->second;
        vectorItTemp = vectorTemp.begin();
        for (; vectorItTemp != vectorTemp.end(); vectorItTemp++) {
            letter = equal;
            letter += vectorItTemp->getCityName()[equal.size()];
            it->second = upperCityName(it->second, equal.size());
            if (allOcur.count(letter) > 0)
                allOcur[letter]++;
            else
                allOcur.insert(std::pair<std::string, int>(letter, 1));
            index++;
        }
    }
    displayFirstLetter(allOcur);
    core->setInput(toLowerCase(equal));
    if (equal.size() > 0)
        findFirstLetter(core);
}
