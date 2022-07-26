/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** gps
*/

#include "Gps.hpp"

void Gps::addAdress(adressSpace::Adress newAdress)
{
    std::vector<adressSpace::Adress> tmp;

    if (this->_allAdressCut.count(newAdress.getCityName()) > 0) {
        tmp = this->_allAdressCut[newAdress.getCityName()];
        tmp.push_back(newAdress);
        this->_allAdressCut[newAdress.getCityName()] = tmp;
    } else {
        tmp.reserve(2);
        tmp.push_back(newAdress);
        this->_allAdressCut.insert(std::pair<std::string, std::vector<adressSpace::Adress>>(newAdress.getCityName(), tmp));
    }
}

void Gps::addInput(std::string input)
{
    this->_inputUser += toLowerCase(input);
}

std::string toUperCase(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](auto c) { return std::toupper(c, std::locale()); });
    return s;
}

std::string Gps::getInput(void)
{
    return (this->_inputUser);
}

std::vector<adressSpace::Adress> Gps::getGoodCity(void)
{
    return (this->_goodCity);
}

adressSpace::Adress Gps::getGoodCityAt(int index)
{
    return (this->_goodCity[index]);
}

void Gps::dislayData()
{
    for(auto x: this->_allAdressCut) {
        std::cout << "\nCity : " << x.first << "\n" << std::endl;
        for(unsigned int i = 0; i < x.second.size(); i++) {
            std::cout << x.second[i].getAllAdress();
            std::cout << " First letter of each city name :" << x.second[i].getfirstLetterCity() << std::endl;
        }
    }
}

std::map<std::string, std::vector<adressSpace::Adress>> Gps::getDico()
{
    return (this->_allAdressCut);
}

bool Gps::getIsGoodCityName()
{
    return (this->_cityNameGood);
}

void Gps::setIsGoodStreetName(bool goodStreetName)
{
    this->_streetNameGood = goodStreetName;
}

bool Gps::getIsGoodStreetName()
{
    return (this->_streetNameGood);
}

void Gps::setIsGoodCityName(bool goodCityName)
{
    this->_cityNameGood = goodCityName;
}

bool Gps::getIsNumInput()
{
    return (this->_numInput);
}

void Gps::setIsNumInput(bool isNumInput)
{
    this->_numInput = isNumInput;
}