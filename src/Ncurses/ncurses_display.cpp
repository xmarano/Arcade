/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_display.cpp
*/

#include "ncurses_setup.hpp"

void Ncurses::draw_sprite(const std::string &spritePath)
{
    (void)spritePath;
}

void Ncurses::display()
{
    cout << "Displaying Ncurses" << endl;
    clear();
    if (gameModule) {
        gameModule->draw_menu(this);
    }
    refresh();
    while (true) {
        int ch = getch();
        if (ch == 'q') {
            break;
        }
    }
}

void Ncurses::draw_box(int width, int height)
{
    box(stdscr, 0, 0);
}

void Ncurses::DrawTitleMenu(const std::string &text)
{
    mvprintw((pos_y / 5) - 10, (pos_x / 2) - 10, "%s", text.c_str()); // Bienvenue sur Arcade !
    mvprintw(0, pos_x - 30, "Appuyer sur 'q' pour quitter");
}
