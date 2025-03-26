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
        mvaddch(entity.y, entity.x, entity.element);
    }
    refresh();
}

int NcursesDisplay::getInput()
{
    int ch = getch();
    switch (ch) {
        case 'q': return -1;
        case 'o': return 2;
        case 'p': return 3;
    }
    return 0;
}

extern "C" IDisplay* create() {
    return new NcursesDisplay();
}
