/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** test_static
*/

#include "algoAdressName.cpp"
#include "algoCityName.cpp"
#include <criterion/criterion.h>

Test(checkStreetNameEqual, two_different_city_with_same_adress)
{
    Gps index;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Piriac, 458 boulevard Saint-Germain");
    bool res;

    index.addGoodCity(tmp1);
    index.addGoodCity(tmp2);
    res = checkStreetNameEqual(&index);

    cr_assert_eq(res, 0);
}

Test (findCityName, no_city_starting_by_p)
{
    Gps index;
    std::vector<adressSpace::Adress> goodCity;
    adressSpace::Adress tmp1 = adressSpace::Adress("Paris, 458 boulevard Saint-Germain");
    adressSpace::Adress tmp2 = adressSpace::Adress("Pariac, 458 boulevard Saint-Germain");

    index.setInput("PARi");
    index.addGoodCity(tmp1);
    index.addGoodCity(tmp2);
    findCityName(&index);

    cr_assert_str_eq(index.getInput().c_str(), "PARI");
}