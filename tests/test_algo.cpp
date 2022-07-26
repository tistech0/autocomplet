/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** test_algoAdress
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Gps.hpp"

Test (displayPropalAdress, one_propal)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    bool res;

    index.addGoodCity(tmp);
    res = displayPropalAdress(&index, 0);

    cr_assert_eq(res, 1);
}

Test (displayPropalAdress, two_propal)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    bool res;

    index.addGoodCity(tmp);
    index.addGoodCity(tmp);
    res = displayPropalAdress(&index, 0);

    cr_assert_eq(res, 0);
}

Test (findFirstLetter, two_city_start_by_p)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Piriac, 458 boulevard Saint-Germain");

    index.setInput("p");
    index.addAdress(tmp1);
    index.addAdress(tmp2);
    findFirstLetter(&index);

    cr_assert_eq(index.getInput().size(), 1);
}

Test (findFirstLetter, one_city_starting_by_p)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Marseille, 458 boulevard Saint-Germain");

    index.setInput("p");
    index.addAdress(tmp1);
    index.addAdress(tmp2);
    findFirstLetter(&index);

    cr_assert_eq(index.getIsGoodCityName(), 1);
}

Test (findFirstLetter, no_city_starting_by_p, .init=cr_redirect_stderr)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Lille, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Marseille, 458 boulevard Saint-Germain");

    index.setInput("p");
    index.addAdress(tmp1);
    index.addAdress(tmp2);
    try
    {
        findFirstLetter(&index);
    }
    catch(const std::exception& e)
    {
        cr_assert("Unknown address");
    }
}

Test (findCity, first_input_p)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Pariac, 458 boulevard Saint-Germain");

    index.setInput("p");
    index.addAdress(tmp1);
    index.addAdress(tmp2);
    findCity(&index);

    cr_assert_eq(index.getGoodCity().size(), 2);
}

Test (findCity, second_input_a)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Pariac, 458 boulevard Saint-Germain");

    index.setInput("Pa");
    index.addGoodCity(tmp1);
    index.addGoodCity(tmp2);
    findCity(&index);

    cr_assert_str_eq(index.getInput().c_str(), "PA");
}