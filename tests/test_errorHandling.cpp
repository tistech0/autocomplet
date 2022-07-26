/*
** EPITECH PROJECT, 2022
** B-SYN-400-NAN-4-1-autoCompletion-matthis.lesur
** File description:
** test_adress
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Gps.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (error_handling, good_input, .init=redirect_all_stdout)
{
    int argc = 2;
    char *argv[0];

    try
    {
        errorHandling(argc, argv);
    }
    catch (const std::exception &e)
    {
        cr_assert("Invalid argument");
    }
}

Test (error_handling, bad_input, .init=redirect_all_stdout)
{
    int argc = 1;
    char *argv[0];

    try
    {
        errorHandling(argc, argv);
    }
    catch (const std::exception &e)
    {
        cr_assert("Invalid argument");
    }
}