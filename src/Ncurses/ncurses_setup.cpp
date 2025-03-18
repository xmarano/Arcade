/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_setup.cpp
*/

#include "ncurses_setup.hpp"
#include "../Game/Menu/Ncurses/nc_display.hpp"

Ncurses::Ncurses() : ADisplayModule("Ncurses")
{
    menuRenderer = new NcursesMenu(this);
}

Ncurses::~Ncurses()
{
    if (menuRenderer != nullptr)
        delete menuRenderer;
    stop();
}

void Ncurses::setTerminalTitle(string title)
{
    std::cout << "\033]0;" << title << "\007";
}

void Ncurses::init()
{
    setTerminalTitle("Arcade");
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void Ncurses::stop()
{
    endwin();
}

void Ncurses::clearScreen()
{
    clear();
}

void Ncurses::refreshScreen()
{
    refresh();
}

extern "C" {
    IDisplayModule *create()
    {
        return new Ncurses();
    }
}

int Ncurses::getScreenWidth()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxX;
}

int Ncurses::getScreenHeight()
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxY;
}
