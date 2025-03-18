/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

void Ncurses::draw_sprite(int x, int y, const std::string &spritePath)
{
    (void)x;
    (void)y;
    (void)spritePath;
}

void Ncurses::display()
{
    clear();
    if (gameModule) {
        gameModule->draw_menu(this);
    }
    mvprintw(20, 10, "Appuyez sur 'q' pour quitter...");
    refresh();
    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }
}

void Ncurses::drawText(int x, int y, const std::string &text)
{
    mvprintw(y, x, "%s", text.c_str());
}
