/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** algo
*/

#include "Gps.hpp"
#include "exceptions/UnknownAddress.hpp"

std::map<std::string, std::vector<adressSpace::Adress>> initPropalAdress(Gps core)
{
    std::string beginNameCity;
    std::map<std::string, std::vector<adressSpace::Adress>> propal;

    for (int j = core.getGoodCity().size() - 1; j >= 0; j--) {
        beginNameCity = core.getGoodCityAt(j).getAdressName().substr(0, (core.getInput().size() + 1) - core.getGoodCity()[0].getCityName().size());
        if (propal.count(beginNameCity) > 0)
            propal[beginNameCity].push_back(core.getGoodCityAt(j));
        else
            propal.insert(std::pair<std::string, int>(beginNameCity, 1));
    }
    return (propal);
}

void findAdress(Gps *core)
{
    std::vector<adressSpace::Adress> vectorTemp = core->getGoodCity();
    std::vector<adressSpace::Adress>::iterator it = vectorTemp.begin();
    std::vector<adressSpace::Adress> tmp;
    std::string tmpCity;
    std::string input = core->getInput().substr(core->getGoodCity()[0].getCityName().size(), core->getInput().size());

    while (it != vectorTemp.end()) {
        if (it->getAdressName().find(input) != std::string::npos && it->getAdressName().find(input) == 0) {
            tmpCity = it->getAdressName();
            tmpCity[(input.size() - 1) - vectorTemp[0].getCityName().size()] = std::toupper(tmpCity[(input.size() - 1) - vectorTemp[0].getCityName().size()]);
            it->setAdressName(tmpCity);
            tmp.push_back(*it);
        }
        it++;
    }
    core->setGoodCity(tmp);
    tmpCity = core->getInput();
    tmpCity[tmpCity.size() - 1] = std::toupper(tmpCity[tmpCity.size() - 1]);
    core->setInput(tmpCity);
}

static void displayPropal(adressSpace::Adress adress, size_t nb)
{
    std::cout << "{" << nb << " : " << adress.getCityName() << ", " << adress.getAdressNumber() << " " << adress.getAdressType() << " " << adress.getAdressName() << "}";
}

static bool checkStreetNameEqual(Gps *core)
{
    std::vector<adressSpace::Adress> tmpVector = core->getGoodCity();

    if (tmpVector.size() != 2)
        return (false);
    if (tmpVector[0].getAdressName() == tmpVector[1].getAdressName()) {
        tmpVector[0].setAdressName(toUpperCase(tmpVector[0].getAdressName()));
        tmpVector[1].setAdressName(toUpperCase(tmpVector[1].getAdressName()));
    } else
        return (false);
    core->setGoodCity(tmpVector);
    displayPropal(core->getGoodCity()[0], 1);
    std::cout << " ";
    displayPropal(core->getGoodCity()[1], 2);
    std::cout << std::endl;
    core->setIsNumInput(true);
    return (true);
}

static std::vector<adressSpace::Adress> resetStreetRef(std::vector<adressSpace::Adress> vectorTemp, size_t goodCityCount, size_t pos)
{
    std::vector<adressSpace::Adress> vector = vectorTemp;
    std::string tmp;

    for (size_t i = 0; i < goodCityCount; i++) {
        tmp = vector.at(i).getAdressName();
        tmp.at(pos) = std::towlower(tmp.at(pos));
        vector.at(i).setAdressName(tmp);
    }
    return (vector);
}

static void updateGoodStreet(Gps *core)
{
    std::vector<adressSpace::Adress> vectorTemp = core->getGoodCity();
    std::string streetRef = vectorTemp[0].getAdressName();
    std::string tmp;
    size_t goodStreetCount = 0;

    for (size_t i = core->getInput().size() - core->getGoodCity()[0].getCityName().size(); i < streetRef.size(); i++) {
        for (size_t j = 0; j < vectorTemp.size(); j++) {
            if (streetRef.at(i) == vectorTemp.at(j).getAdressName().at(i)) {
                tmp = vectorTemp.at(j).getAdressName();
                tmp.at(i) = std::toupper(tmp.at(i));
                vectorTemp.at(j).setAdressName(tmp);
                goodStreetCount++;
            }
        }
        if (goodStreetCount != core->getGoodCity().size()) {
            vectorTemp = resetStreetRef(vectorTemp, goodStreetCount, i);
            break;
        }
        else {
            tmp = core->getInput();
            tmp += std::toupper(streetRef.at(i));
            core->setInput(tmp);
            goodStreetCount = 0;
        }
    }
    core->setGoodCity(vectorTemp);
}

bool displayPropalAdress(Gps *core, int flag)
{
    std::map<std::string, std::vector<adressSpace::Adress>> propal;
    std::map<std::string, std::vector<adressSpace::Adress>>::iterator it;
    size_t i = 0;
    (void)flag;

    if (core->getGoodCity().size() == 1) {
        std::cout << "=> " << core->getGoodCity()[0].getAllAdress() << std::endl;
        return (true);
    } else if (core->getGoodCity().size() == 0)
        throw UnknownAddressError();
    if (checkStreetNameEqual(core) == true)
        return (false);
    updateGoodStreet(core);
    propal = initPropalAdress(*core);
    it = propal.begin();
    while (it != propal.end()) {
        std::cout << "{" << core->getGoodCity()[0].getCityName() << ", " << it->first << "}";
        if (i < propal.size() - 1)
            std::cout << " ";
        it++;
        i++;
    }
    std::cout << std::endl;
    return (false);
}