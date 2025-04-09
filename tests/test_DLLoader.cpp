/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** test_DLLoader
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Core/DLLoader.hpp"
#include "../include/Core/DisplayInterface.hpp"

Test(DLLoader, constructor)
{
    DLLoader<IDisplay> loader;
    cr_assert(true, "DLLoader constructor should not throw exceptions");
}

Test(DLLoader, load_nonexistent_library)
{
    DLLoader<IDisplay> loader;
    bool exceptionCaught = false;
    try {
        loader.load("nonexistent_library.so");
    } catch (const ArcadeException &e) {
        exceptionCaught = true;
    }
    cr_assert(exceptionCaught, "Loading a nonexistent library should throw an ArcadeException");
}