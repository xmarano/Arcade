/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Ncurses.cpp
*/

#include "ncurses_setup.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <cstring>

extern "C" IDisplayModule* create()
{
    return new Ncurses();
}

Ncurses::Ncurses() : ADisplayModule("ncurses")
{
    return;
}

void Ncurses::init()
{
    std::cout << "[ncurses] Entry point for ncurses !" << std::endl;

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    if (has_colors()) {
        start_color();
    }
    timeout(0);
}

void Ncurses::display()
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

void Ncurses::stop()
{
    endwin();
    cout << "[ncurses] ncurses stopping ..." << endl;
}
