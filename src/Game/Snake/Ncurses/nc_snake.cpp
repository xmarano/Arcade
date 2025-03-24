/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** nc_snake.cpp
*/

#include "nc_snake.hpp"
#include "../../../ArcadeExeption.hpp"

NcursesSnake::NcursesSnake(Ncurses *nc) : nc(nc) {}

void NcursesSnake::print_map()
{
    // int screenWidth = this->nc->getScreenWidth();
    // int screenHeight = this->nc->getScreenHeight();

    this->nc->DrawText1(0, 0, "COUCOU SNAKE!");
}

SnakeEvent NcursesSnake::pollEvent()
{
    int ch = getch();

    switch (ch) {
        case 'q':
            return SnakeEvent::Quit;
        case 'm':
            return SnakeEvent::BackToMenu;
        case 'o':
            return SnakeEvent::SwapToSdl2;
        case 'p':
            return SnakeEvent::SwapToSfml;
        case KEY_UP:
            return SnakeEvent::UP;
        case KEY_DOWN:
            return SnakeEvent::Down;
        case KEY_LEFT:
            return SnakeEvent::Left;
        case KEY_RIGHT:
            return SnakeEvent::Right;
        default:
            return SnakeEvent::None;
    }
    return SnakeEvent::None;
}

void NcursesSnake::quit()
{
    this->nc->stop();
    exit(0);
}
