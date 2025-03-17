/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses.cpp
*/

#include "nc_menu.hpp"
#include <ncurses.h>
#include <cstring>
#include <unistd.h>

Menu::Menu()
{
    return;
}

void Menu::draw_menu()
{
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    while (true) {
        clear();

        const char *message = "Hello World !!!";
        int message_length = strlen(message);
        int y = max_y / 2;
        int x = (max_x - message_length) / 2;

        mvprintw(y, x, "%s", message);
        refresh();

        int ch = getch();
        if (ch == 'q' || ch == 'Q') {
            break;
        }
        usleep(100000);
    }
}
