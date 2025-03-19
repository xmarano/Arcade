/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.cpp
*/

#include "nc_menu.hpp"

NcursesMenu::NcursesMenu(Ncurses* nc) : nc(nc) {}

int getScreenWidth()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxX;
}

int getScreenHeight()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxY;
}

void NcursesMenu::Draw_Module1()
{
    pos_x = getScreenWidth();
    pos_y = getScreenHeight();
}

void NcursesMenu::Draw_Module2()
{

}

void NcursesMenu::Draw_Module3()
{

}
