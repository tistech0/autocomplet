/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** utils
*/

#include "Gps.hpp"

std::vector<adressSpace::Adress> upperCityName(std::vector<adressSpace::Adress> allAdress, int pos)
{
    std::string tmpCity = allAdress[0].getCityName();

    tmpCity[pos] = std::toupper(tmpCity[pos]);
    for (size_t i = 0; i < allAdress.size(); i++) {
        allAdress[i].setCityName(tmpCity);
    }
    return (allAdress);
}

std::string toUpperCase(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](auto c) { return std::toupper(c, std::locale()); });
    return s;
}