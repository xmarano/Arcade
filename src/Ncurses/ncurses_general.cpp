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
    while (true) {
        clearScreen();
        if (gameModule)
            gameModule->draw_game(this);
        refreshScreen();
        int ch = getch();
        if (ch == 'q') {
            break;
        }
        // if (ch == 'n') {
        //     // loader.changeLibrary(current_display, "./lib/arcade_ncurses.so");
        // }
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

