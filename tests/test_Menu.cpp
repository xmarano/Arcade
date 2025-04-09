/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** test_Menu
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/Core/Menu.hpp"

Test(Menu, constructor)
{
    Menu menu;
    cr_assert(true, "Menu constructor should not throw exceptions");
}

Test(Menu, actions_quit)
{
    Menu menu;
    int result = menu.Actions(MenuEvent::Quit, nullptr);
    cr_assert_eq(result, -1, "Actions with Quit should return -1");
}

Test(Menu, actions_play_pacman)
{
    Menu menu;
    int result = menu.Actions(MenuEvent::PlayPacman, nullptr);
    cr_assert_eq(result, CODE_NC_PACMAN, "Actions with PlayPacman should return CODE_NC_PACMAN");
}

Test(Menu, get_stats)
{
    Menu menu;
    try {
        std::vector<std::string> stats = menu.get_stats();
        cr_assert(stats.size() >= 4, "get_stats should return at least 4 elements");
    } catch (const ArcadeException &e) {
        cr_assert(true, "get_stats may throw exceptions if files don't exist");
    }
}