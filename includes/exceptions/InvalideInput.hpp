/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** UnknownAddress
*/

#pragma once


#include <exception>

class InvalideAddressError : public std::exception
{
public:
    const char *what() const throw()
    {
        return "";
    }
};
