/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** gps
*/

#pragma once

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
#include <map>
#include <utility>

#include "Adress.hpp"

/**
 * Implementation of Gps class
 *
 * Gps class is the main class of the program. it conatain
 * all information like dictyonar and actual good city selected.
 *
 */

class Gps
{
    public:
        Gps() { _cityNameGood = false; _numInput = false; };
        ~Gps() = default;

        void addAdress(adressSpace::Adress newAdress);
        void dislayData();
        void addInput(std::string input);
    
        std::string getLastInput(void);
        std::string getInput(void);
        std::vector<adressSpace::Adress> getGoodCity(void);
        adressSpace::Adress getGoodCityAt(int index);
        std::map<std::string, std::vector<adressSpace::Adress>> getDico();
        bool getIsGoodCityName();
        void setIsGoodCityName(bool goodCityName);
        bool getIsGoodStreetName();
        void setIsGoodStreetName(bool goodStreetName);
        bool getIsNumInput();
        void setIsNumInput(bool isNumInput);

        void setDico(std::map<std::string, std::vector<adressSpace::Adress>> dico) { _allAdressCut = dico; };
        std::vector<adressSpace::Adress> getFirstAdress(void) { std::map<std::string, std::vector<adressSpace::Adress>>::iterator it = getDico().begin(); return (it->second); };
        void setGoodCity(std::vector<adressSpace::Adress> goodCity) { _goodCity.clear(); _goodCity = goodCity; };
        void addGoodCity(adressSpace::Adress goodCity) { _goodCity.push_back(goodCity); };
        void setInput(std::string input) { _inputUser = input; };

    private:
        std::map<std::string, std::vector<adressSpace::Adress>> _allAdressCut;
        std::string _inputUser;
        std::vector<adressSpace::Adress> _goodCity;
        std::vector<std::string> _propal;
        bool _cityNameGood;
        bool _streetNameGood;
        bool _numInput;
};

/**
 * errorHandling
 *
 * @param int argc number of argument pass in parameter
 * @param char *argv[] array of argument pass in parameter
 */
bool errorHandling(int argc, char *argv[]);

/**
 * loadFile is here to load dictionary in core map
 *
 * @param char *filepath is path to dictionary
 * @param Gps *core class containing all information
 */
int loadFile(char *filepath, Gps *core);

/**
 * coreLoop is were all the algorithme work
 *
 * @param Gps* core class containing all information
 */
void coreLoop(Gps core);


/**
 * FindCity mean each time there is new input and no city is validate search in
 *
 * @param Gps* core class containing all information
 */
void findCity(Gps *core);

/**
 * displayPropalCityName mean display all new propositon to find a city name 
 * if there is one city with only one adress remaining display it
 *
 * @param Gps* core class containing all information
 */
bool displayPropalCityName(Gps *core);

/**
 * findFirstLetter mean check the first letter of each city
 *
 * @param Gps* core class containing all information
 */
void findFirstLetter(Gps *core);

/**
 * updateGoodCity mean update good city with new validate adress
 *
 * @param Gps* core class containing all information
 */
void updateGoodCity(Gps *core);

/**
 * propalBegin mean display the first choice for the user to find adress
 *
 * @param Gps* core class containing all information
 */
void propalBegin(Gps *core);

/**
 * findAdress mean ach time there is new input and city is validate search in
 *
 * @param Gps* core class containing all information
 */
void findAdress(Gps *core);

/**
 * displayPropalAdress mean display all new propositon to find a adress 
 *
 * @param Gps* core class containing all information
 */
bool displayPropalAdress(Gps *core, int flag);

/**
 * upperCityName mean change to upper case all city name at pos  
 *
 * @param vector<adressSpace::Adress> allAdress vector of good adress
 * @param int pos where we want to put upper case
 */
std::vector<adressSpace::Adress> upperCityName(std::vector<adressSpace::Adress> allAdress, int pos);

/**
 * toUpperCase mean change to upper case all string
 *
 * @param std::string s string to pass in upper case
 */
std::string toUpperCase(std::string s);
