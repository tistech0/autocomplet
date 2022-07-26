/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** algo
*/

#include "Gps.hpp"
#include "exceptions/UnknownAddress.hpp"

void findFirstLetter(Gps *core)
{
    std::map<std::string, std::vector<adressSpace::Adress>> mapTemp = core->getDico();
    std::map<std::string, std::vector<adressSpace::Adress>>::iterator it = mapTemp.begin();
    std::string tmp;
    int checkNbGoodcity = 0;

    while (it != mapTemp.end()) {
        if (it->first.find(core->getInput()) != std::string::npos && it->first.find(core->getInput()) == 0) {
            it->second = upperCityName(it->second, core->getInput().size() - 1);
            for (size_t i = 0; i < it->second.size(); i++)
                core->addGoodCity(it->second[i]);
            checkNbGoodcity++;
        }
        it++;
    }
    tmp = core->getInput();
    tmp[tmp.size() - 1] = std::toupper(tmp[tmp.size() - 1]);
    core->setInput(tmp);
    if (checkNbGoodcity == 1)
        core->setIsGoodCityName(true);
    else if (checkNbGoodcity == 0)
        throw UnknownAddressError();
}

static void findCityName(Gps *core)
{
    std::vector<adressSpace::Adress> vectorTemp = core->getGoodCity();
    std::vector<adressSpace::Adress>::iterator it = vectorTemp.begin();
    std::vector<adressSpace::Adress> tmp;
    std::string tmpCity;

    while (it != vectorTemp.end()) {
        if (it->getCityName().find(core->getInput()) != std::string::npos && it->getCityName().find(core->getInput()) == 0) {
            tmpCity = it->getCityName();
            tmpCity[core->getInput().size() - 1] = std::toupper(tmpCity[core->getInput().size() - 1]);
            it->setCityName(tmpCity);
            tmp.push_back(*it);
        }
        it++;
    }
    core->setGoodCity(tmp);
    tmpCity = core->getInput();
    tmpCity[tmpCity.size() - 1] = std::toupper(tmpCity[tmpCity.size() - 1]);
    core->setInput(tmpCity);
}

void findCity(Gps *core)
{
    if(core->getGoodCity().size() == 0 && core->getInput().size() == 1)
        findFirstLetter(core);
    else
        findCityName(core);
}

static std::vector<adressSpace::Adress> resetCityRef(std::vector<adressSpace::Adress> vectorTemp, size_t goodCityCount, size_t pos)
{
    std::vector<adressSpace::Adress> vector = vectorTemp;
    std::string tmp;

    for (size_t i = 0; i < goodCityCount; i++) {
        tmp = vector.at(i).getCityName();
        tmp.at(pos) = std::towlower(tmp.at(pos));
        vector.at(i).setCityName(tmp);
    }
    return (vector);
}

void updateGoodCity(Gps *core)
{
    std::vector<adressSpace::Adress> vectorTemp = core->getGoodCity();
    std::string cityRef;
    std::string tmp;
    size_t goodCityCount = 0;

    if (vectorTemp.size() > 0)
        cityRef = vectorTemp[0].getCityName();
    else
        return;

    for (size_t i = core->getInput().size(); i < cityRef.size(); i++) {
        for (size_t j = 0; j < vectorTemp.size(); j++) {
            if (cityRef.at(i) == vectorTemp.at(j).getCityName().at(i)) {
                tmp = vectorTemp.at(j).getCityName();
                tmp.at(i) = std::toupper(tmp.at(i));
                vectorTemp.at(j).setCityName(tmp);
                goodCityCount++;
            }
        }
        if (goodCityCount != core->getGoodCity().size()) {
            vectorTemp = resetCityRef(vectorTemp, goodCityCount, i);
            break;
        }
        else if (goodCityCount > 0){
            tmp = core->getInput();
            tmp += std::toupper(cityRef.at(i));
            core->setInput(tmp);
            goodCityCount = 0;
        }
    }
    core->setGoodCity(vectorTemp);
}

static std::map<std::string, std::vector<adressSpace::Adress>> initPropalCityName(Gps *core)
{
    std::string beginNameCity;
    std::map<std::string, std::vector<adressSpace::Adress>> propal;

    updateGoodCity(core);
    for (int j = core->getGoodCity().size() - 1; j >= 0; j--) {
        beginNameCity = core->getGoodCityAt(j).getCityName().substr(0, core->getInput().size() + 1);
        if (propal.count(beginNameCity) > 0)
            propal[beginNameCity].push_back(core->getGoodCityAt(j));
        else
            propal.insert(std::pair<std::string, int>(beginNameCity, 1));
    }
    return (propal);
}

static void propalCityName(Gps *core)
{
    std::map<std::string, std::vector<adressSpace::Adress>> propal = initPropalCityName(core);
    std::map<std::string, std::vector<adressSpace::Adress>>::iterator it = propal.begin();
    size_t i = 0;

    if (propal.size() == 1) {
        core->setIsGoodCityName(true);
        return;
    }
    while (it != propal.end()) {
        std::cout << "{" << it->first << "}";
        if (i < propal.size() - 1)
            std::cout << " ";
        it++;
        i++;
    }
    std::cout << std::endl;
}

bool displayPropalCityName(Gps *core)
{
    if (core->getGoodCity().size() == 1) {
        std::cout << "=> " << core->getGoodCity()[0].getAllAdress() << std::endl;
        return (true);
    } else
        propalCityName(core);
    return (false);
}
