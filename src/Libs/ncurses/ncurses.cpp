/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-arcade-yanis.prevost
** File description:
** Ncurses.cpp
*/

#include "ncurses.hpp"

void NcursesDisplay::init()
{
    initscr();
    start_color();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

void NcursesDisplay::close()
{
    endwin();
}

void NcursesDisplay::render(const GameState &state)
{
    clear();
    for (const auto& entity : state.entities) {
        mvaddch(entity.y, entity.x, entity.type);
    }
    refresh();
}

int NcursesDisplay::getInput()
{
    int ch = getch();
    switch (ch) {
        case 'o':
            return 2;
        case 'p':
            return 3;
        case 'q':
            return -1;
    }
    return 0;
}

extern "C" IDisplay* create() {
    return new NcursesDisplay();
}
