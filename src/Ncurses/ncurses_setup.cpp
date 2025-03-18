/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** ncurses_setup.cpp
*/

#include "ncurses_setup.hpp"

Ncurses::Ncurses() : ADisplayModule("Ncurses") {}

Ncurses::~Ncurses()
{
    stop();
}

void Ncurses::init()
{
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

int Ncurses::getScreenWidth() const
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxX;
}

int Ncurses::getScreenHeight() const
{
    int maxX, maxY;

    getmaxyx(stdscr, maxY, maxX);
    return maxY;
}
