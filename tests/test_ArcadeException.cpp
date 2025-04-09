/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** test_ArcadeException
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Core/ArcadeException.hpp"
#include <string>

Test(ArcadeException, constructor_with_message)
{
    const std::string errorMessage = "Test error message";
    ArcadeException exception(errorMessage);
    cr_assert_str_eq(exception.what(), errorMessage.c_str(),
                    "Exception message doesn't match expected value");
}

Test(ArcadeException, throw_and_catch)
{
    bool exceptionCaught = false;
    const std::string errorMessage = "Test throw message";
    try {
        throw ArcadeException(errorMessage);
    } catch (const ArcadeException& e) {
        exceptionCaught = true;
        cr_assert_str_eq(e.what(), errorMessage.c_str(), "Caught exception message doesn't match expected value");
    }
    cr_assert(exceptionCaught, "Exception was not caught");
}