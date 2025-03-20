/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_Snake.cpp
*/
#include "nc_snake.hpp"
#include "../../../ArcadeExeption.hpp"

NcursesSnake::NcursesSnake(Ncurses *nc) : nc(nc) {}

void NcursesSnake::print_map(std::string *map, int score, int lives)
{
    int screenWidth = this->nc->getScreenWidth();
    int screenHeight = this->nc->getScreenHeight();

    mvprintw(0, 0, "Score: %d", score);
    mvprintw(1, 0, "Lives: %d", lives);
    for (int i = 0; i < MAP_HEIGHT; i++) {
        mvprintw(i + screenHeight / 2 - (MAP_HEIGHT / 2), screenWidth / 2 - (MAP_HEIGHT / 2), map[i].c_str());
    }
}
