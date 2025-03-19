/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

void Ncurses::display()
{
    cout << "Displaying Ncurses" << endl;
    clearScreen();
    if (gameModule) {
        gameModule->draw_game(this);
    }
    refreshScreen();
    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }
}

void Ncurses::DrawText1(int pos_x, int pos_y, string mess)
{
    mvprintw(pos_y, pos_x, "%s", mess.c_str());
}

void Ncurses::DrawText2(int pos_x, int pos_y, string mess)
{
    DrawText1(pos_x, pos_y, mess);
}

