/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** Adress
*/

#include <iostream>
#include <sstream>
#include <regex>
#include <cstring>

#include "Adress.hpp"

using namespace adressSpace;

std::string toLowerCase(std::string s) 
{
    std::transform(s.begin(), s.end(), s.begin(), [](auto c) { return std::tolower(c, std::locale()); });
    return s;
}

Adress::Adress()
{
    this->_nbLetterValidateCity = 0;
}

Adress::Adress(std::string allAdress)
{
    std::vector<std::string> adressCut;
    char *dup;
    char *tmp;

    this->_allAdress = allAdress;
    allAdress = toLowerCase(allAdress);
    dup = strdup(allAdress.c_str());
    this->_cityName = std::strtok(dup, ",");
    this->_adressNumber = std::strtok(NULL, " ");
    this->_adressType = std::strtok(NULL, " ");
    this->_adressName = std::strtok(NULL, "\0");
    free(dup);
    dup = strdup(this->_cityName.c_str());
    this->_firstLetterCity.push_back(dup[0]);
    tmp = std::strtok(dup, " ");
    while ((tmp = std::strtok(NULL, " ")))
        this->_firstLetterCity.push_back(tmp[0]);
    free(dup);
    this->_nbLetterValidateCity = 0;
}