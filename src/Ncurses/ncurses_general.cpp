/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

int Ncurses::display()
{
    int code = 0;

    clearScreen();
    if (gameModule) {
        code = gameModule->draw_game(this);
        if (code > 0)
            return code;
    }
    refreshScreen();
    return 0;
}

void Ncurses::DrawText1(int pos_x, int pos_y, string mess)
{
    mvprintw(pos_y, pos_x, "%s", mess.c_str());
}

void Ncurses::DrawText2(int pos_x, int pos_y, string mess)
{
    DrawText1(pos_x, pos_y, mess);
}
