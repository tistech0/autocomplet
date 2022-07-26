/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** errorHandling
*/

#include "Gps.hpp"
#include "exceptions/InvalideArgument.hpp"

bool errorHandling(int agrc, char *argv[])
{
    (void)argv;
    if (agrc != 2)
        throw InvalideArgumentError();
    return (true);
}
