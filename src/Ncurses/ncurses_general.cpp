/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

Event Ncurses::pollEvent()
{
    int ch = getch();

    if (ch == 'q')
        return Event::Quit;
    if (ch == 's')
        return Event::SwitchToSDL2;
    // if (ch == KEY_DOWN)
    //     return Event::Down;
    // if (ch == KEY_UP)
    //     return Event::Up;
    return Event::None;
}

void Ncurses::display()
{
    clearScreen();
    if (gameModule)
        gameModule->draw_game(this);
    refreshScreen();
}

void Ncurses::DrawText1(int pos_x, int pos_y, string mess)
{
    mvprintw(pos_y, pos_x, "%s", mess.c_str());
}

void Ncurses::DrawText2(int pos_x, int pos_y, string mess)
{
    DrawText1(pos_x, pos_y, mess);
}
