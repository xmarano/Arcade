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
    clear();
    refresh();
}

void NcursesDisplay::close()
{
    if (!isendwin()) {
        endwin();
    }
}

void NcursesDisplay::render(const GameState &state)
{
    clear();
    for (const auto& entity : state.entities) {
        mvaddch(entity.y, entity.x, entity.element); //! mvprintw fait de la merde
    }
    refresh();
}

void NcursesDisplay::renderText(const std::string &text, int x, int y)
{
    mvprintw(y, x, text.c_str());
}

int NcursesDisplay::getInput()
{
    // nodelay(stdscr, TRUE); //! sus mais ca marche..
    int ch = getch();

    switch (ch) {
        case 'q': return -1;
        case 'o': return 2;
        case 'p': return 3;
        case KEY_UP: return 5;
        case KEY_DOWN: return 6;
        case KEY_LEFT: return 7;
        case KEY_RIGHT: return 8;
        case '\n': return 10;
    }
    return 0;
}

int NcursesDisplay::getScreenWidth()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxX;
}

int NcursesDisplay::getScreenHeight()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxY;
}


extern "C" IDisplay* create()
{
    return new NcursesDisplay();
}
