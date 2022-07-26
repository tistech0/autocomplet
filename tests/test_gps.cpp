/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** test_adress
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Gps.hpp"

Test (addAdress, geter_adress)
{
    adressSpace::Adress france = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    cr_assert_str_eq(france.getCityName().c_str(), "paris");
    cr_assert_str_eq(france.getAdressNumber().c_str(), "458");
    cr_assert_str_eq(france.getAdressType().c_str(), "boulevard");
    cr_assert_str_eq(france.getAdressName().c_str(), "saint-germain");
    cr_assert_eq(france.getfirstLetterCity()[0], 'p');
}

Test (addAdress, geter_adress_with_two_word_city)
{
    adressSpace::Adress france = adressSpace::Adress("La Rochelle, 458 boulevard Saint-Germain");
    cr_assert_str_eq(france.getCityName().c_str(), "la rochelle");
    cr_assert_str_eq(france.getAdressNumber().c_str(), "458");
    cr_assert_str_eq(france.getAdressType().c_str(), "boulevard");
    cr_assert_str_eq(france.getAdressName().c_str(), "saint-germain");
    cr_assert_eq(france.getfirstLetterCity()[0], 'l');
    cr_assert_eq(france.getfirstLetterCity()[1], 'r');
}

Test (addAdress, add_adress_gps)
{
    Gps index;
    adressSpace::Adress france = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress france_two = adressSpace::Adress("Paris, 234 boulevard Saint-Germain");
    index.addAdress(france);
    index.addAdress(france_two);
}

Test (dislayData, display_two_address)
{
    Gps index;
    adressSpace::Adress france = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress france_two = adressSpace::Adress("Paris, 234 boulevard Saint-Germain");
    index.addAdress(france);
    index.addAdress(france_two);
    index.dislayData();
}

Test (addInput, add_simple_input_min)
{
    Gps index;

    index.addInput("a");
    cr_assert_str_eq(index.getInput().c_str(), "a");
}

Test (addInput, add_simple_input_maj)
{
    Gps index;

    index.addInput("A");
    cr_assert_str_eq(index.getInput().c_str(), "a");
}

Test (toUperCase, pass_string_lower_to_upper)
{
    std::string str("hello world");

    str = toUpperCase(str);
    cr_assert_str_eq(str.c_str(), "HELLO WORLD");
}

Test (getGoodCity, get_good_city)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    
    index.addGoodCity(tmp);
    goodCity = index.getGoodCity();

    cr_assert_eq(goodCity.size(), 1);
}

Test (getGoodCityAt, get_good_city_at)
{
    Gps index;
    adressSpace::Adress tmp = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress res;

    index.addGoodCity(tmp);
    res = index.getGoodCityAt(0);

    cr_assert_eq(res.getAllAdress().size(), 34);
}

Test (getDico, get_ditionary)
{
    Gps index;
    adressSpace::Adress tmp = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    std::map<std::string, std::vector<adressSpace::Adress>> dico;

    index.addAdress(tmp);
    dico = index.getDico();

    cr_assert_eq(dico.size(), 1);
}

Test (getIsGoodCityName, get_set_IsGoodCityName)
{
    Gps index;

    index.setIsGoodCityName(false);

    cr_assert_eq(index.getIsGoodCityName(), 0);
}

Test (getIsGoodStreetName, get_set_IsGoodStreetName)
{
    Gps index;

    index.setIsGoodStreetName(false);

    cr_assert_eq(index.getIsGoodStreetName(), 0);
}

Test (getIsNumInput, get_set_IsNumInput)
{
    Gps index;

    index.setIsNumInput(false);

    cr_assert_eq(index.getIsNumInput(), 0);
}