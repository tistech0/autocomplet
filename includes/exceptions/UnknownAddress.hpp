/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** UnknownAddress
*/

#pragma once


#include <exception>

/**
 * UnknownAddressError
 *
 * Error if input enter by user is in any adress
 *
 */

class UnknownAddressError : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Unknown address\n";
    }
};
