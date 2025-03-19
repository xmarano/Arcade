/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_pacman.cpp
*/

#include "nc_pacman.hpp"
#include "../../../ArcadeExeption.hpp"

NcursesPacman::NcursesPacman(Ncurses *nc) : nc(nc) {}

void NcursesPacman::print_map(std::string *map)
{
    int screenWidth = this->nc->getScreenWidth();
    int screenHeight = this->nc->getScreenHeight();

    for (int i = 0; i < MAP_HEIGHT; i++) {
        mvprintw(i + screenHeight / 2 - (MAP_HEIGHT / 2), screenWidth / 2 - (MAP_HEIGHT / 2), map[i].c_str());
    }
}