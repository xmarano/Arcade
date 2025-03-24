/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_pacman.cpp
*/

#include "nc_pacman.hpp"
#include "../../../ArcadeExeption.hpp"

NcursesPacman::NcursesPacman(Ncurses *nc) : nc(nc) {}

void NcursesPacman::print_map(std::string *map, int score, int lives, int level, int highscore)
{
    int screenWidth = this->nc->getScreenWidth();
    int screenHeight = this->nc->getScreenHeight();

    this->nc->DrawText1(0, 0, "Hight socre: " + to_string(highscore));
    this->nc->DrawText1(0, 1, "Lives: " + to_string(lives));
    this->nc->DrawText1(0, 2, "Score: " + to_string(score));
    this->nc->DrawText1(0, 3, "Level: " + to_string(level));
    for (int i = 0; i < MAP_HEIGHT; i++) {
        this->nc->DrawText1(screenWidth / 2 - (MAP_HEIGHT / 2), screenHeight / 2 - (MAP_HEIGHT / 2) + i, map[i]);
    }
}

PacmanEvent NcursesPacman::pollEvent()
{
    int ch = getch();

    switch (ch) {
        case 'q':
            return PacmanEvent::Quit;
        case 'm':
            return PacmanEvent::BackToMenu;
        case 'o':
            return PacmanEvent::SwapToSdl2;
        case 'p':
            return PacmanEvent::SwapToSfml;
        case KEY_UP:
            return PacmanEvent::UP;
        case KEY_DOWN:
            return PacmanEvent::Down;
        case KEY_LEFT:
            return PacmanEvent::Left;
        case KEY_RIGHT:
            return PacmanEvent::Right;
        default:
            return PacmanEvent::None;
    }
    return PacmanEvent::None;
}

void NcursesPacman::quit()
{
    this->nc->stop();
    exit(0);
}
