/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_display.cpp
*/

#include "nc_display.hpp"
#include "../../../Ncurses/ncurses_setup.hpp"
#include <fstream>

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

    nc->DrawText1((pos_x / 4) / 1.5, (pos_y / 4) / 1.5, "Jeux disponibles");
}

void NcursesMenu::Draw_Module2()
{

}

void NcursesMenu::Draw_Module3()
{

}
