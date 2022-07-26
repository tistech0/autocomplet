/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** InvalideArgument
*/

#pragma once

#include <exception>

/**
 * InvalideArgumentError
 *
 * Error if there is not enought argument or too much,
 * if the dictionary is empty or if there is no good adress
 *
 */

class InvalideArgumentError : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Invalid argument\n";
    }
};
