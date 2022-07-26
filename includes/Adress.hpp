/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** Adress
*/

#pragma once

#include <string>
#include <vector>
#include <algorithm>

namespace adressSpace
{

/**
 * Implementation of adress 
 *
 * Adress contain all part of adress string gramar
 * cut in part to be parse by the algorythme
 * 
 */

class Adress {
    public:
        Adress();
        Adress(std::string allAdress);
        ~Adress() = default;

        std::string getAllAdress() const { return (_allAdress); };
        std::string getCityName() const { return (_cityName); };
        std::string getAdressNumber() const { return (_adressNumber); };
        std::string getAdressType() const { return (_adressType); };
        std::string getAdressName() const { return (_adressName); };
        std::string getfirstLetterCity() const { return (_firstLetterCity); };
        std::string getfirstLetterAdressName() const { return (_firstLetterAdressName); };
        int getNbGoodLetter() const { return (_nbLetterValidateCity); };

        void setAllAdress(std::string allAdress) { _allAdress = allAdress; };
        void setCityName(std::string cityName) { _cityName = cityName; };
        void setAdressNumber(std::string adressNumber) { _adressNumber = adressNumber; };
        void setAdressType(std::string adressType) { _adressType = adressType; };
        void setAdressName(std::string adressName) { _adressName = adressName; };
        void setfirstLetterCity(std::string firstLetterCity) { _firstLetterCity = firstLetterCity; };
        void setfirstLetterAdressName(std::string firstLetterAdressName) { _firstLetterAdressName = firstLetterAdressName; };

        void setNbLetterValidateCity(int nbLetterValidateCity) { _nbLetterValidateCity = nbLetterValidateCity;};

    private:
        std::string _allAdress;
        std::string _cityName;
        std::string _adressNumber;
        std::string _adressType;
        std::string _adressName;
        std::string _firstLetterCity;
        std::string _firstLetterAdressName;
        int _nbLetterValidateCity;
};

} // namespace adressSpace

std::string toLowerCase(std::string s);